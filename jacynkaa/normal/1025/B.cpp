#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

const int stala=1000000;
bool pierwsz_do_pieriwastka [stala];

void pre()
{
    pierwsz_do_pieriwastka[0]=pierwsz_do_pieriwastka[1]=false;

    for (int i=2; i<stala; i++)
    {
        pierwsz_do_pieriwastka[i]=true;
    }
    for (int i=0; i<stala; i++)
    {
        if(pierwsz_do_pieriwastka[i]==true)
        {
            for (int j=2*i; j<stala; j=j+i)
                pierwsz_do_pieriwastka[j]=false;
        }
    }
}

vector <int> P;
vector <bool> X;

void rob (int a)
{
    for (int i=0; i<stala; i++)
    {
        if(pierwsz_do_pieriwastka[i]==true && (a%i)==0)
        {
            P.push_back(i);
            while (a%i==0)
                a=a/i;

        }
    }
    if(a>1)
    P.push_back(a);

}

main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    vector <int> A(n);
    vector <int> B(n);

    pre();
    for (int i=0; i<n; i++)
    {
        cin>>A[i]>>B[i];
    }
    rob(A[0]);
    rob(B[0]);
      X.resize(P.size(), true);

  //  for (int i=0; i<P.size(); i++)
   //     cout <<P[i]<<" ";
//    cout <<endl;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<P.size(); j++)
            if(A[i]%P[j]!=0 && B[i]%P[j]!=0)
                X[j]=false;
    }

    for (int j=0; j<P.size(); j++)
    {
        if(X[j]==true)
        {
            cout <<P[j]<<endl;
            return 0;
        }
    }
    cout <<-1<<endl;
}