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



const int rozmiar=1000009;
const int inf=(long long)(1e18)+18;
int prime[] = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

vector <int> D;

int ile_kwadratow (int N)
{
    int p=1;
    int q=1000000009;
    while (p!=q)
    {
        int s=(p+q+1)/2;
        if(s*s==N)
            return s;
        if(s*s<N)
            p=s;
        if(s*s>N)
            q=s-1;
    }
    return p;
}

bool potega (int co, int do_ktorej)
{

//cout <<co<<" "<<do_ktorej<<endl;
    unsigned long long a=1;
    for (int i=0; i<do_ktorej; i++)
    {
  //  cout <<a<<endl;
        a=a*co;
        if(a>inf)
        return false;
    }

    D.push_back(a);
    return true;
}



main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    vector <int> tab (rozmiar);

    for (int i=1; i<rozmiar; i++)
    {
        if(i*i<rozmiar)
            tab[i*i]=1;
    }


    for (int i=0; i<23; i++)
    {
        int a=1;
        bool czy_dalej=true;
        while (czy_dalej)
        {
      //  cout <<a<<endl;
            if(tab[a]!=1)
                czy_dalej=potega(a, prime[i]);
            a++;
        }
    }


    sort(D.begin(), D.end());



    D.resize(unique(D.begin(), D.end())- D.begin());
/*
cout <<"D"<<endl;
    for (int i=0; i<10; i++)
       cout <<D[i]<<endl;
*/

    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        cout<<n-(upper_bound(D.begin(),D.end(), n)-D.begin())-ile_kwadratow(n)<<endl;
        //cout <<n<<" "<<(lower_bound(D.begin(),D.end(), n)-D.begin())<<" "<<ile_kwadratow(n)<<endl;
    }
}