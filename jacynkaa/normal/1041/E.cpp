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

    int n;
    cin>>n;


       vector <int> porzadek (n,0);
    vector <int> kraw ;
    porzadek[n-1]=n;

    for (int i=0; i<n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        if(a!=n && b!=n)
        {
            cout <<"NO"<<endl;
            return 0;
        }
        kraw.push_back(min(a,b));
    }

    sort(kraw.begin(), kraw.end());
    reverse(kraw.begin(), kraw.end());

    vector <int> ile (n,0);
/*
    for (int i=0;i<kraw.size();i++)
    cout <<kraw[i]<<" "<<endl;
*/
    int x=n-1;
    for (int i=0; i<kraw.size(); i++)
    {
        if(kraw[i]<x)
        {
            cout <<"NO"<<endl;
            return 0;
        }
        x--;
        ile[kraw[i]]++;
    }
/*
    for (int i=0;i<n;i++)
    cout <<ile[i]<<" ";
    cout <<endl;
*/

    int obec=n-1;
    queue<int> nie;

    for (int i=n-1; i>0; i--)
    {
        if(ile[i]>0)
        {
            obec=obec-ile[i];
            porzadek[obec]=i;
        }
        else
        {
            nie.push(i);
        }
    }
/*
    for (int i=0;i<porzadek.size();i++)
    cout <<porzadek[i]<<" ";
    cout <<endl;
*/
    for (int i=n-1; i>=0; i--)
    {
        if(porzadek[i]==0)
        {
            porzadek[i]=nie.front();
            nie.pop();
        }
    }

    cout <<"YES"<<endl;
    for (int i=0; i<n-1; i++)
        cout <<porzadek[i]<<" "<<porzadek[i+1]<<endl;
}