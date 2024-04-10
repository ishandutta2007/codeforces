#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define int long long

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    int n;
    cin>>n;
    string A;
    string B;



    int ile_dobrych []= {0,0};
    int ile_zlych[]= {0,0};

    cin>>A>>B;


    for (int i=0; i<n; i++)
    {
    A[i]-='0';
    B[i]-='0';

        if(A[i]==1 && B[i]==1)
            ile_zlych[1]++;

        if(A[i]==0 && B[i]==1)
            ile_zlych[0]++;

        if(A[i]==0 && B[i]==0)
            ile_dobrych[0]++;

        if(A[i]==1 && B[i]==0)
            ile_dobrych[1]++;
    }

    cout <<(ile_dobrych[0]+ile_zlych[0])*ile_dobrych[1]+(ile_dobrych[1]+ile_zlych[1])*ile_dobrych[0]-ile_dobrych[0]*ile_dobrych[1]<<endl;
}