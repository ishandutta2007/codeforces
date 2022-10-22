#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll n,i,a[ 1000005 ],cnt;

int main()
{
    cin >> n ;
    for(i=1;i<=n;i++) cin >> a[i];
    for(i=1;i<=n;i++)
        while( a[i] != i )
        swap( a[i] , a[ a[i] ]),cnt++;
    cout << (n%2==cnt%2? "Petr" : "Um_nik"  );
	return 0;
}