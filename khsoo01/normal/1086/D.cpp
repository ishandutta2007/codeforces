#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;

const int N = 200005, L = (1<<18);
const char Z[4] = "RPS";

int n, q, b[N];
char a[N];

struct segtree {
    int v[2*L];
    void upd (int P, int V) {
        P += L;
        while(P) {
            v[P] += V;
            P /= 2;
        }
    }
    int get (int S, int E) {
        S += L; E += L;
        int R = 0;
        while(S <= E) {
            if(S%2 == 1) R += v[S++];
            if(E%2 == 0) R += v[E--];
            S /= 2; E /= 2;
        }
        return R;
    }
    int fw () {
        int P = 1;
        while(P < L) {
            if(v[2*P]) P = 2*P;
            else P = 2*P+1;
        }
        return min(P-L, n+1);
    }
    int bw () {
        int P = 1;
        while(P < L) {
            if(v[2*P+1]) P = 2*P+1;
            else P = 2*P;
        }
        return P-L;
    }
} seg[3];

int Count () {
    vector<pii> A, B;
    for(int i=0;i<3;i++) {
        A.push_back({seg[i].fw(), i});
        B.push_back({seg[i].bw(), i});
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int la = ((A[0].Y + 1) % 3 == A[1].Y ? A[0].Y : A[1].Y);
    int lb = ((B[1].Y + 1) % 3 == B[2].Y ? B[1].Y : B[2].Y);
    pii pa = {A[1].X, A[2].X-1}, pb = {B[0].X+1, B[1].X};
    if(la == lb) {
        if(pa.X <= pb.X && pb.X <= pa.Y) return seg[la].get(pa.X, max(pb.Y, pa.Y));
        else if(pb.X <= pa.X && pa.X <= pb.Y) return seg[la].get(pb.X, max(pa.Y, pb.Y));
    }
    return seg[la].get(pa.X, pa.Y) + seg[lb].get(pb.X, pb.Y);
}

int main()
{
    scanf("%d%d%s",&n,&q,a+1);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            if(a[i] == Z[j]) {
                b[i] = j;
                break;
            }
        }
        seg[b[i]].upd(i, 1);
    }
    printf("%d\n", n-Count());
    while(q--) {
        int A, B;
        char C[2];
        scanf("%d%s",&A,C);
        for(int i=0;i<3;i++) {
            if(C[0] == Z[i]) {
                B = i;
                break;
            }
        }
        seg[b[A]].upd(A, -1);
        seg[B].upd(A, 1);
        b[A] = B;
        printf("%d\n", n-Count());
    }
}