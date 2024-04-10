#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<math.h>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define double long double
#define fi first
#define se second
#define int long long

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

const int z=1234567890;

vector <vector <int> > G;
vector <int> odwiedzony; //1 odwiedzony
vector <int> najdluzszy;
int odp=1;
int n,k;


void dfs(int x)
{
    odwiedzony[x]=1;
    vector <int> A;
    for (int i=0; i<G[x].size(); i++)
        if(odwiedzony[G[x][i]]==0)
            A.push_back(G[x][i]) ;

    for (int i=0; i<A.size(); i++)
        dfs(A[i]);

    vector<int> C;

    for (int i=0; i<A.size(); i++)
        C.push_back(najdluzszy[A[i]]);

        if(A.size()==0)
        return ;

    sort(C.begin(), C.end());
    reverse(C.begin(),C.end());
    C.push_back(-1234567);



    for (int i=0; i<C.size(); i++)
        if(C[i]+C[i+1]+2>k)
            odp++;
        else
        {
            najdluzszy[x]=C[i]+1;
            return;
        }
}

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);



    cin>>n>>k;
    G.resize(n);
    najdluzszy.resize(n,0);
    odwiedzony.resize(n,0);

    for (int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ktory=-1;

    for (int i=0; i<n; i++)
        if(G[i].size()>1)
            ktory=i;

    dfs(ktory);
/*
    cout <<"K:  "<<ktory<<endl;

    for (int i=0;i<n;i++)
    {
    cout <<i<<": "<<najdluzszy[i]<<" ?? ";
    for (int j=0;j<G[i].size();j++)
    cout <<G[i][j]<<" ";
    cout <<endl;
    }
    */
cout <<odp<<endl;
}