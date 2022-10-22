#include <bits/stdc++.h>
using namespace std;

int ans;

int main()
{
int a,b,f,k;

cin>>a>>b>>f>>k;
if(f>b||a-f>b){cout<<-1;return 0;}
if(k>1&&2*(a-f)>b){cout<<-1;return 0;}
if(k>2&&2*f>b){cout<<-1;return 0;}
int l=b-f;
for(int i=0;i<k-1;i++)
{
//cout<<l<<endl;

if(i%2==0){if(l<2*(a-f)){ans++;l=b-2*(a-f);}else{l-=2*(a-f);}}
if(i%2==1){if(l<2*f){ans++;l=b-2*f;}else{l-=2*f;}}


}
int i=k-1;
if(i%2==0){if(l<a-f){ans++;l=b;}}
if(i%2==1){if(l<f){ans++;l=b;}}
cout<<ans;
return 0;}