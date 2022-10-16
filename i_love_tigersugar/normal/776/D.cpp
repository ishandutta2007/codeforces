#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

class TwoSat {
    private:
    struct Node {
        int low, num, compID;
        vector<int> adj;

        Node() {
            low = num = compID = 0;
        }
    };
    struct Component {
        int topo, value;
        vector<int> negative, adj;

        Component() {
            topo = value = -1;
        }
    };

    void dfs(int u) {
        nodes[u].low = nodes[u].num = ++cnt;
        st.push(u);
        FORE(it, nodes[u].adj) if (nodes[*it].compID == 0) {
            int v = *it;
            if (nodes[v].num == 0) {
                dfs(v);
                minimize(nodes[u].low, nodes[v].low);
            } else minimize(nodes[u].low, nodes[v].num);
        }

        if (nodes[u].low == nodes[u].num) {
            numComp++;
            while (true) {
                int v = st.top(); st.pop();
                nodes[v].compID = numComp;
                if (u == v) break;
            }
        }
    }
    void dfsTopo(int u) {
        FORE(it, components[u].adj) if (components[*it].topo < 0) dfsTopo(*it);
        components[u].topo = --cnt;
    }
    void assignValue(int comp, int value) {
        if (components[comp].value >= 0) {
            assert(components[comp].value == value);
            return;
        }
        components[comp].value = value;
        FORE(it, components[comp].negative) assignValue(*it, 1 - value);
        if (value > 0) {
            FORE(it, components[comp].adj) assignValue(*it, value);
        }
    }

    #define POSITIVE   true
    #define NEGATIVE   false

    int numNode, cnt, numComp;
    vector<Node> nodes;
    vector<Component> components;
    stack<int> st;

    public:
    TwoSat(int n = 0) {
        numNode = n;
        cnt = numComp = 0;
        nodes.assign(2 * n + 7, Node());
    }

    #define NODE_ID(id, type) ((type) == POSITIVE ? (id) : (id) + numNode)
    void addChoiceCondition(int var1, bool type1, int var2, bool type2) { //Condition type: A or B
        assert(1 <= var1 && var1 <= numNode);
        assert(1 <= var2 && var2 <= numNode);
        nodes[NODE_ID(var1, !type1)].adj.push_back(NODE_ID(var2, type2));
        nodes[NODE_ID(var2, !type2)].adj.push_back(NODE_ID(var1, type1));
    }
    void addMustFalseCondition(int var) { //Condition type: A = false
        addChoiceCondition(var, NEGATIVE, var, NEGATIVE);
    }
    void addMustTrueCondition(int var) { //Condition type: B = true
        addChoiceCondition(var, POSITIVE, var, POSITIVE);
    }
    void addInferCondition(int var1, bool type1, int var2, bool type2) { //Condition type: A -> B
        addChoiceCondition(var1, !type1, var2, type2);
    }

    bool haveSolution(void) {
        FOR(i, 1, 2 * numNode) if (nodes[i].num == 0) dfs(i);
        FOR(i, 1, numNode) if (nodes[NODE_ID(i, true)].compID == nodes[NODE_ID(i, false)].compID) return false;
        return true;
    }

    vector<bool> getSolution(void) {
        if (!haveSolution()) return vector<bool>();
        components.assign(numComp + 7, Component());

        FOR(i, 1, numNode) {
            int posComp = nodes[NODE_ID(i, true)].compID;
            int negComp = nodes[NODE_ID(i, false)].compID;
            components[posComp].negative.push_back(negComp);
            components[negComp].negative.push_back(posComp);
        }

        FOR(u, 1, 2 * numNode) FORE(it, nodes[u].adj) if (nodes[u].compID != nodes[*it].compID)
            components[nodes[u].compID].adj.push_back(nodes[*it].compID);
        FOR(i, 1, numComp) if (components[i].topo < 0) dfsTopo(i);
        vector<pair<int, int> > allCompID;
        FOR(i, 1, numComp) allCompID.push_back(make_pair(components[i].topo, i));
        sort(ALL(allCompID));
        FORE(it, allCompID) if (components[it->se].value < 0) assignValue(it->se, false);
        vector<bool> res;
        FOR(i, 1, numNode) res.push_back(components[nodes[i].compID].value);
        return res;
    }

    bool testSolution(const vector<bool> &value) {
        FOR(i, 1, 2 * numNode) FORE(it, nodes[i].adj) {
            int j = *it;
            int vi = i <= numNode ? value[i] : !value[i - numNode];
            int vj = j <= numNode ? value[j] : !value[j - numNode];
            if (vi && !vj) {
                printf("Failed inference from %d to %d\n", i, j);
                return false;
            }
        }
        return true;
    }
};


/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   200200
vector<int> canOpen[MAX];
int cur[MAX], n, m;

void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &cur[i]);
    FOR(i, 1, m) {
        int t; scanf("%d", &t);
        REP(love, t) {
            int x; scanf("%d", &x);
            canOpen[x].push_back(i);
        }
    }
}

void process(void) {
    TwoSat ts(m);

    FOR(i, 1, n) {
        assert(canOpen[i].size() == 2);
        int x = canOpen[i][0];
        int y = canOpen[i][1];
        assert(x != y);

        if (cur[i] == 0) {
            ts.addChoiceCondition(x, POSITIVE, y, POSITIVE);
            ts.addChoiceCondition(x, NEGATIVE, y, NEGATIVE);
        } else {
            ts.addChoiceCondition(x, POSITIVE, y, NEGATIVE);
            ts.addChoiceCondition(x, NEGATIVE, y, POSITIVE);
        }
    }

    cout << (ts.haveSolution() ? "YES" : "NO") << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/