#include<bits/stdc++.h>
using namespace std;
int mn=9999999,mx=0;
bool f = false;
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n];
    for( int i=0;i<n;i++ )
   {
       cin >> arr[i];
   }
   while( clock()*1000/CLOCKS_PER_SEC < 1400 ){}
   	sort(arr,arr+n);
   for( int i=0;i<n;i++ )
   {
       cout<<arr[i]<<" ";
   }
}