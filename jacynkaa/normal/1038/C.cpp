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
    vector <int> A (n);
    vector <int> B(n);



    for (int i=0; i<n; i++)
        cin>>A[i];
    for (int i=0; i<n; i++)
        cin>>B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());


    int wynik=0;

    for (int i=0; i<n; i++)
    {
        bool zrobione1=false;
        if(A.size()==0)
        {
            zrobione1=true;
            B.pop_back();
        }
        if(B.size()==0 && zrobione1==false)
        {
            zrobione1=true;
            wynik+=A[A.size()-1];
            A.pop_back();
        }
        if( zrobione1==false && A[A.size()-1]<B[B.size()-1])
        {
            zrobione1=true;
            B.pop_back();
        }

        if(zrobione1==false)
        {
            zrobione1=true;
            wynik+=A[A.size()-1];
            A.pop_back();
        }

        zrobione1=false;


        if(A.size()==0)
        {
            zrobione1=true;
            wynik-=B[B.size()-1];
            B.pop_back();

        }
        if(B.size()==0 && zrobione1==false)
        {
            zrobione1=true;
            A.pop_back();
        }
        if( zrobione1==false && A[A.size()-1]<B[B.size()-1])
        {
            zrobione1=true;
            wynik-=B[B.size()-1];
            B.pop_back();
        }

        if(zrobione1==false)
        {
            zrobione1=true;
            A.pop_back();
        }

    }

    cout <<wynik<<endl;
    }