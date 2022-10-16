#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector <pair<int, int> > X;

    for (int i=0; i<n; i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        auto x=mp(a+b+c+d,-i);
        X.push_back(x);
    }
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());

   // for (int i=0; i<n; i++)
   // cout <<i<<": "<<X[i].first<<" "<<X[i].second<<endl;

    for (int i=0; i<n; i++)
        if(X[i].second==0)
            cout <<i+1<<endl;



}