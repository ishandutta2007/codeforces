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


int tab [19];

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    tab[0]=1;
    for (int i=1; i<19; i++)
        tab[i]=tab[i-1]*10;

    vector <int> wygenerowane;

    for (int i=0; i<18; i++)
        for (int j=i+1; j<18; j++)
            for (int k=j+1; k<18; k++)
                for (int r1=1; r1<10; r1++)
                    for (int r2=1; r2<10; r2++)
                        for (int r3=1; r3<10; r3++)
                        {
                            int a=tab[i]*r1+tab[j]*r2+tab[k]*r3;
                            wygenerowane.push_back(a);
                        }

    for (int i=0; i<18; i++)
        for (int j=i+1; j<18; j++)
            for (int r1=1; r1<10; r1++)
                for (int r2=1; r2<10; r2++)
                {
                    int a=tab[i]*r1+tab[j]*r2;
                    wygenerowane.push_back(a);
                }

    for (int i=0; i<18; i++)
        for (int r1=1; r1<10; r1++)

        {
            int a=tab[i]*r1;
            wygenerowane.push_back(a);
        }

    sort(wygenerowane.begin(), wygenerowane.end());
    wygenerowane.push_back((long long )(1e18));
/*
    for (int i=0; i<10000; i++)
        cout <<wygenerowane[i]<<endl;
        cout <<wygenerowane[wygenerowane.size()-1]<<endl;8*/


    int T;
    cin>>T;
    while (T--)
    {
        int l,r;
        cin>>l>>r;
        int  c=lower_bound(wygenerowane.begin(), wygenerowane.end(), l)-wygenerowane.begin();
       int d=upper_bound(wygenerowane.begin(), wygenerowane.end(), r)-wygenerowane.begin();
       cout <<d-c<<endl;
    }
}