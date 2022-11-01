#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

struct node {
    int mxP, mnP;
    node (int _mxP=0, int _mnP=0) : mxP(_mxP), mnP(_mnP) {}
};


int readQ() {
    char a;
    scanf (" %c", &a);
    if (a == '<') {
        return -1;
    } else if (a == '=') {
        return 0;
    } else {
        return 1;
    }
}
int mkQ (int a, int b) {
    printf ("? %d %d\n", a, b);
    fflush (stdout);
    return readQ();
}
int T, N;

int main() {
    scanf ("%d", &T);
    FO (_z,0,T) {
        scanf ("%d", &N);
        queue <node> allN;
        while (!allN.empty()) allN.pop();
        FO (i,0,N) {
            allN.push (node (i+1, i+1));
        }
        while (allN.size() > 1) {
            node fNode = allN.front();
            allN.pop();
            node sNode = allN.front();
            allN.pop();
            node newNode;
            if (fNode.mxP == fNode.mnP && sNode.mxP == sNode.mnP) {
                int res = mkQ (fNode.mxP, sNode.mxP);
                if (res <= 0) {
                    newNode = node(sNode.mxP, fNode.mxP);
                } else {
                    newNode = node(fNode.mxP, sNode.mxP);
                }
            } else {
                int res = mkQ (fNode.mxP, sNode.mxP);
                if (res <= 0) {
                    newNode.mxP = sNode.mxP;
                } else {
                    newNode.mxP = fNode.mxP;
                }
                res = mkQ (fNode.mnP, sNode.mnP);
                if (res <= 0) {
                    newNode.mnP = fNode.mnP;
                } else {
                    newNode.mnP = sNode.mnP;
                }
            }
            allN.push (newNode);
        }
        node cNode = allN.front();
        printf ("! %d %d\n", cNode.mnP, cNode.mxP);
        fflush (stdout);
    }
    return 0;
}