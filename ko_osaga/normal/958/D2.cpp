#include<bits/stdc++.h>
using namespace std;
using frac = pair<long long, long long>;
frac mul(frac a, frac b)
{
    return frac(a.first * b.first, a.second*b.second);
}
frac add(frac a, frac b)
{
    return frac(a.first*b.second+b.first*a.second, a.second*b.second);
}
frac div(frac a, frac b)
{
    return frac(a.first*b.second, a.second*b.first);
}
frac minusv(frac a)
{
    a.first *= -1;
    return a;
}
frac sub(frac a, frac b)
{
    return add(a, minusv(b));
}
frac norm(frac a)
{
    if(a.second < 0)
    {
        a.first *= -1;
        a.second *= -1;
    }
    auto g = __gcd(abs(a.first), abs(a.second));
    
    return frac(a.first/g, a.second/g);
}
bool iszero(frac a)
{
    return a.first == 0;
}
void printRREF(vector<vector<frac>> V)
{
    for(auto x: V)
    {
        printf("|");
        for(auto y: x)
            printf("%7lld/%7lld|",y.first, y.second);
        puts("");
    }
    puts("");
}
vector<vector<frac> > RREF(vector<vector<frac> > A)
{
    int N = A[0].size();
    int r = 0;
    //printf("%d %d\n", (int)A.size(), N); fflush(stdout);
    for(int i=0; i<N; ++i)
    {
        for(int j=r; j<A.size(); ++j)
        {
            if(!iszero(A[j][i]))
            {
                swap(A[r], A[j]);
                break;
            }
        }
        if(iszero(A[r][i])) continue;
        frac piv = A[r][i];
        for(int j=0; j<N; ++j) A[r][j] = norm(div(A[r][j], piv));
        for(int j=0; j<A.size(); ++j) 
        {
            if(j==r) continue;
            for(int k=0; k<N; ++k)
            {
                if(k==i) continue;
                A[j][k] = norm(sub(A[j][k], norm(mul(A[r][k], A[j][i]))));
            }
            A[j][i] = frac(0, 1);
        }
        ++r;
        if(r==A.size()) break;
    }
    //printRREF(A);
    //puts("RREFEND"); fflush(stdout);
    for(int i=0; i<A.size(); ++i)
    {
        bool flag = false;
        for(int j=0; j<N; ++j)
        {
            A[i][j] = norm(A[i][j]);
            if(!iszero(A[i][j])) flag = true;
        }
        if(!flag){
            while((int)A.size() >= i+1) A.pop_back();
        }
    }
    return A;
}
int ans[35252];
int M, D;
int main()
{
    scanf("%d%d", &M, &D);
    vector< pair<vector<vector<frac>>, int> > tot;
    for(int i=0; i<M; ++i)
    {
        //puts("OK"); fflush(stdout);
        int N; scanf("%d", &N);
        vector<vector<frac> > V;
        for(int i=0; i<N; ++i)
        {
            vector<frac> Q;
            for(int i=0; i<D; ++i)
            {
                int x; scanf("%d", &x);
                Q.emplace_back(x, 1);
            }
            V.push_back(Q);
        }
        //printRREF(V);
        //puts("OK"); fflush(stdout);
        tot.emplace_back(RREF(V), i+1);
        //puts("OK"); fflush(stdout);
    }
    sort(tot.begin(), tot.end());
    vector<vector<int> > A;
    vector<int> V; V.push_back(tot[0].second);
    
    for(int i=1; i<tot.size(); ++i)
    {
        if(tot[i].first == tot[i-1].first) V.push_back(tot[i].second);
        else
        {
            sort(V.begin(), V.end());
            A.push_back(V);
            V.clear();
            V.push_back(tot[i].second);
        }
    }
    sort(V.begin(), V.end());
    A.push_back(V);
    sort(A.begin(), A.end());
    for(int i=0; i<A.size(); ++i)
    {
        for(auto j: A[i])
            ans[j] = i+1;
    }
    for(int i=1; i<=M; ++i)
        printf("%d ", ans[i]);
    puts("");
}