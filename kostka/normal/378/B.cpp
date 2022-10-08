#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>

using namespace std;

vector <pair <int, int> > A, B, C;

const int MAXN = 100007;
bool ta[MAXN], tb[MAXN];

int main()
{
    int n, a, b;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &a, &b);
        A.push_back(make_pair(a, i));
        B.push_back(make_pair(b, i));
        C.push_back(make_pair(a, i));
        C.push_back(make_pair(b, -i));
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    for(int i=0; i<n; i++)
    {
        if(C[i].second > 0)
            ta[C[i].second] = 1;
        else
            tb[-C[i].second] = 1;
    }
    for(int i=0; i<n/2; i++)
    {
        ta[A[i].second] = 1;
        tb[B[i].second] = 1;
    }
    for(int i=1; i<=n; i++)
        printf("%d", ta[i]);
    printf("\n");
    for(int i=1; i<=n; i++)
        printf("%d", tb[i]);
}