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

main()
{
ios_base::sync_with_stdio(false);
cout.precision(10);
 cout.setf(ios::fixed);

int x,y,z,t1,t2,t3;
cin>>x>>y>>z>>t1>>t2>>t3;

int A=abs(x-y)*t1;
int B=(abs(x-z)+abs(x-y))*t2+3*t3;

if(A>=B)
cout <<"YES"<<endl;
else
cout <<"NO"<<endl;

//cout <<A<<" "<<B<<endl;
}