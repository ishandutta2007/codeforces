#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

int nextInt(void) {
    int x; assert(cin >> x); return x;
}

const int MOD = (int)1e9 + 7;
void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const int ALPHABET_SIZE = 26;
struct Node {
    Node *parent;
    int parChar, index;
    Node *children[ALPHABET_SIZE];

    Node *fail, *next[ALPHABET_SIZE];
    int totValue;

    Node(int index = 0, Node *parent = nullptr, int parChar = -1) {
        this->parent = parent;
        this->parChar = parChar;
        fail = nullptr;
        REP(i, ALPHABET_SIZE) children[i] = next[i] = nullptr;
        this->index = index; totValue = 0;
    }
};

#define MAX_NODE   222
Node nodes[MAX_NODE];
int numNode;
Node *root;
Node* createNode(Node *parent, int parChar) {
    nodes[numNode] = Node(numNode, parent, parChar);
    numNode++;
    return &nodes[numNode - 1];
}

void addString(const vector<int> &digits, int value) {
    Node *p = root;
    FORE(it, digits) {
        if (p->children[*it] == nullptr) p->children[*it] = createNode(p, *it);
        p = p->children[*it];
    }
    p->totValue += value;
}

void AC_BFS() {
    root->fail = root;
    REP(i, ALPHABET_SIZE) root->next[i] = root->children[i] != nullptr ? root->children[i] : root;
    root->totValue = 0;

    queue<Node*> q;
    REP(i, ALPHABET_SIZE) if (root->children[i] != nullptr) q.push(root->children[i]);

    while (!q.empty()) {
        Node *p = q.front(); q.pop();
        p->fail = p->parent == root ? root : p->parent->fail->next[p->parChar];
        p->totValue += p->fail->totValue;
        REP(i, ALPHABET_SIZE) p->next[i] = p->children[i] != nullptr ? p->children[i] : p->fail->next[i];
        REP(i, ALPHABET_SIZE) if (p->children[i] != nullptr) q.push(p->children[i]);
    }
}

#define MAX_LEN   222
#define MAX_LIMIT   555
int numWord, base, limit;
vector<int> leftNumber, rightNumber;
int f[MAX_LEN][MAX_NODE][MAX_LIMIT][2][2];

void init(void) {
    cin >> numWord >> base >> limit;
    REP(love, nextInt()) leftNumber.push_back(nextInt());
    REP(love, nextInt()) rightNumber.push_back(nextInt());

    root = createNode(nullptr, -1);
    root = &nodes[0];
    REP(love, numWord) {
        vector<int> number;
        REP(love, nextInt()) number.push_back(nextInt());
        addString(number, nextInt());
    }

    AC_BFS();
}

int countString(const vector<int> &digits) { // count all valid numbers whose are less than <digits>
    REP(i, digits.size() + 1) REP(j, numNode) memset(f[i][j], 0, sizeof f[i][j]);

    f[0][0][0][0][1] = 1;
    REP(pos, digits.size()) REP(node, numNode) REP(total, limit + 1) REP(cmp, 2) REP(zero, 2)
        if (f[pos][node][total][cmp][zero] > 0) REP(nextDigit, base) {
            if (!cmp && nextDigit > digits[pos]) continue;
            int newCmp = cmp || nextDigit < digits[pos];
            int newZero = zero && nextDigit == 0;
            Node* newNode = newZero ? root : nodes[node].next[nextDigit];
            int newTotal = total + newNode->totValue;
            if (newTotal <= limit) {
                add(f[pos + 1][newNode->index][newTotal][newCmp][newZero], f[pos][node][total][cmp][zero]);
            }

        }

    int res = 0;
    REP(i, numNode) REP(j, limit + 1) add(res, f[digits.size()][i][j][1][0]);
    cerr << "RETURN " << res << endl;
    return res;
}

bool ok(const vector<int> &digits) { // verify the total value of matched strings is not greater than limit
    int totValue = 0;
    Node *p = root;
    FORE(it, digits) {
        p = p->next[*it];
        totValue += p->totValue;
    }
    return totValue <= limit;
}

void process(void) {
    cout << (countString(rightNumber) - countString(leftNumber) + MOD + ok(rightNumber)) % MOD << endl;
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/