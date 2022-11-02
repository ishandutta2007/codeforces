#include<bits/stdc++.h>
using namespace std;

int tree[1000005];
int licz[1000005];
int board[305][305];
int pot = (1<<18);
const int duzo = 1e5+6;
void przenumeruj(vector<int> &v)
{
    set<int> s;
    vector<int> v2;
    for(auto x:v)
        s.insert(x);
    for(auto x:s)
        v2.push_back(x);
    for(auto &x:v)
        x = (lower_bound(v2.begin(),v2.end(),x) - v2.begin()) + 1;
}

void ins(int a,int b)
{
    int pom = a + pot;
    while(pom != 0)
    {
        tree[pom] += b;
        pom /= 2;
    }
}

int check(int a,int b)
{
    int l = a + pot, r = b + pot;
    int war = tree[l];
    if(l != r)
        war += tree[r];
    while(l/2 != r/2)
    {
        if(l % 2 == 0)
            war += tree[l+1];
        if(r % 2 == 1)
            war += tree[r-1];
        l/=2;
        r/=2;
    }
    return war;

}

void solve()
{
    int a,b;
    cin>>a>>b;
    vector<int> v;
    for(int x=0;x<a*b;x++)
    {
        int c;
        cin>>c;
        v.push_back(c);
    }
    przenumeruj(v);
    for(auto x:v)
        ins(x,1);
    long long res = 0;
    for(auto x:v)
    {
        int pom = check(0, x-1);
        pom += licz[x];
        int row = pom/b, col = pom%b;
        //cout<<row<<" "<<col<<'\n';
        for(int y=0;y<col;y++)
            if(board[row][y] < x && board[row][y] != 0)
                res++;
        board[row][col] = x;
        licz[x]++;
    }
    cout<<res<<'\n';
    for(int x=0;x<a;x++)
        for(int y=0;y<b;y++)
            board[x][y] = 0;
    for(auto x:v)
    {
        ins(x,-1);
        licz[x] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}