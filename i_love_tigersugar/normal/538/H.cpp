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
#define DEBUG   false

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

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
        if (DEBUG) printf("Choose between %d (%s) and %d (%s)\n\n", var1, type1 ? "TRUE" : "FALSE", var2, type2 ? "TRUE" : "FALSE");
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
        if (DEBUG) printf("Infer from %d (%s) to %d (%s)\n", var1, type1 ? "TRUE" : "FALSE", var2, type2 ? "TRUE" : "FALSE");
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

#define MAX   100100
const char YES[] = "POSSIBLE";
const char NO[] = "IMPOSSIBLE";

pair<int, int> hater[MAX], range[MAX];
vector<int> candidates;
int n, m, minSum, maxSum;

void init(void) {
    scanf("%d%d%d%d", &minSum, &maxSum, &n, &m);
    FOR(i, 1, n) scanf("%d%d", &range[i].fi, &range[i].se);
    FOR(i, 1, m) scanf("%d%d", &hater[i].fi, &hater[i].se);
}

void oneGroupCase(void) {
    if (m > 0) return;
    int maxL = range[1].fi;
    int minR = range[1].se;
    FOR(i, 1, n) {
        maximize(maxL, range[i].fi);
        minimize(minR, range[i].se);
    }
    if (maxL > minR || maxL > maxSum) return;
    int tmp = maxL;
    printf("%s\n", YES);
    printf("%d %d\n", tmp, max(minSum - tmp, 0));
    FOR(i, 1, n) printf("1"); printf("\n");
    exit(0);
}

void findCandidate(void) {
    FOR(i, 1, n) REP(j, 2) REP(k, 2) {
        int tmp = j ? range[i].fi : range[i].se;
        int val = k ? tmp : minSum - tmp;
        if (val >= 0 && val <= maxSum) candidates.push_back(val);
    }
    candidates.push_back(0);
    sort(ALL(candidates));
    candidates.resize(unique(ALL(candidates)) - candidates.begin());
    if (DEBUG) FORE(it, candidates) printf("%d ", *it); if (DEBUG) printf("\n");
}

void process(void) {
    int numCandidate = candidates.size();
    TwoSat twoSat(2 * numCandidate + n);

    #define X1_VAR(x) (x)
    #define X2_VAR(x) ((x) + numCandidate)
    #define PERSON_VAR(x) ((x) + 2 * numCandidate)

    //conditions: if x1 <= candidates[t] then x1 <= candidates[t + 1]
    FOR(i, 1, numCandidate - 1) {
        twoSat.addInferCondition(X1_VAR(i), POSITIVE, X1_VAR(i + 1), POSITIVE);
        twoSat.addInferCondition(X2_VAR(i), POSITIVE, X2_VAR(i + 1), POSITIVE);
    }
    twoSat.addMustTrueCondition(X1_VAR(numCandidate));
    twoSat.addMustTrueCondition(X2_VAR(numCandidate));

    //conditions: x1 + x2 >= minSum
    if (DEBUG) printf("x1 + x2 >= minSum\n");
    int j = numCandidate - 1;
    REP(i, candidates.size()) {
        while (j >= 0 && candidates[i] + candidates[j] >= minSum) j--;
        if (j >= 0) twoSat.addChoiceCondition(X1_VAR(i + 1), NEGATIVE, X2_VAR(j + 1), NEGATIVE);
    }

    //conditions: x1 + x2 <= maxSum
    if (DEBUG) printf("x1 + x2 <= maxSum\n");
    j = numCandidate;
    FOR(i, 1, numCandidate - 1) {
        while (j > 0 && candidates[i] + candidates[j - 1] > maxSum) j--;
        if (j < numCandidate) twoSat.addChoiceCondition(X1_VAR(i), POSITIVE, X2_VAR(j), POSITIVE);
    }

    //conditions for teacher belongs to the first and second group
    if (DEBUG) printf("Teacher to segment\n");
    FOR(i, 1, n) {
        int L = lower_bound(ALL(candidates), range[i].fi) - candidates.begin() + 1;
        int R = upper_bound(ALL(candidates), range[i].se) - candidates.begin() + 1;
        if (L > 1) {
            twoSat.addInferCondition(PERSON_VAR(i), POSITIVE, X1_VAR(L - 1), NEGATIVE);
            twoSat.addInferCondition(PERSON_VAR(i), NEGATIVE, X2_VAR(L - 1), NEGATIVE);
        }
        twoSat.addInferCondition(PERSON_VAR(i), POSITIVE, X1_VAR(R - 1), POSITIVE);
        twoSat.addInferCondition(PERSON_VAR(i), NEGATIVE, X2_VAR(R - 1), POSITIVE);
    }

    //conditions for conflicting pairs of teacher
    if (DEBUG) printf("Haters\n");
    FOR(i, 1, m) {
        int x = hater[i].fi;
        int y = hater[i].se;
        twoSat.addChoiceCondition(PERSON_VAR(x), POSITIVE, PERSON_VAR(y), POSITIVE);
        twoSat.addChoiceCondition(PERSON_VAR(x), NEGATIVE, PERSON_VAR(y), NEGATIVE);
    }

//    vector<bool> value(1, false);
//    int x1 = 49;
//    int x2 = 150;
//    FOR(i, 1, numCandidate) value.push_back(candidates[i - 1] >= x1);
//    FOR(i, 1, numCandidate) value.push_back(candidates[i - 1] >= x2);
//    string tmp = "21121221121112211222";
//    FOR(i, 1, n) value.push_back(tmp[i - 1] == '1');
//    printf("numCan: %d numPer: %d\n", numCandidate, n);
//    assert(twoSat.testSolution(value));

    vector<bool> result = twoSat.getSolution();
    if (result.empty()) {
        printf("%s\n", NO);
        return;
    }
    //FORE(it, result) printf("%d ", (int)*it); printf("\n");
    printf("%s\n", YES);
    FOR(i, 1, numCandidate) if (result[X1_VAR(i) - 1]) {
        printf("%d ", candidates[i - 1]);
        break;
    }
    FOR(i, 1, numCandidate) if (result[X2_VAR(i) - 1]) {
        printf("%d\n", candidates[i - 1]);
        break;
    }
    FOR(i, 1, n) printf("%c", result[PERSON_VAR(i) - 1] ? '1' : '2');
    printf("\n");
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    oneGroupCase();
    findCandidate();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/