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



main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    // cout <<nwd(4,6)<<endl;

    int n,m,d;
    cin>>n>>m>>d;

    vector <int> O(n);
    int odp=0;
    queue<pair<int, int> > Q;

    vector <int> X(n);

    for (int i=0; i<n; i++)
        cin>>X[i];

    vector <int> oryginal=X;

    sort(X.begin(),X.end());


    for (int i=0; i<n; i++)
    {
        if(Q.empty() || Q.front().fi+d+1>X[i])
        {
            odp++;
            Q.push(mp(X[i],odp));
            O[i]=odp;
        }

        else
        {
        //cout <<"Q: "<<Q.front().fi+d+1<<" "<<X[i]<<endl;
            int a=Q.front().se;
            Q.pop();
            Q.push(mp(X[i],a));
            O[i]=a;
        }
       // cout <<Q.front().fi<<" "<<Q.front().se<<endl;
    }

    cout <<odp<<endl;
    for (int i=0; i<n; i++)
        cout <<(O[lower_bound(X.begin(),X.end(), oryginal[i])-X.begin()])<<" ";
    cout <<endl;
}