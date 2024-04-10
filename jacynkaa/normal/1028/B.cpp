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

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x


const int stala=1000;

main()
{
int n,m;
cin>>n>>m;

for (int i=0;i<stala;i++)
cout <<9;
for (int i=0;i<stala-1;i++)
cout <<0;
cout <<1<<endl;

for (int i=0;i<stala;i++)
cout <<9;
cout <<endl;

}