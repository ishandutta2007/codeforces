#include <bits/stdc++.h>
#include <math.h>
#include <map>
#include<string>
using namespace std;
string s;bool str[1000];int cnt,n,k,a[1000],j=1;
int main()
{

cin>>n>>k;
for(int i=0;i<k;i++){cin>>a[i];str[a[i]]=true;}
for(int i=0;i<k;i++)
{
    cout<<a[i]<<" ";cnt=n-1;
    while(cnt!=0) {while(str[j])j++;cout<<j++<<" ";cnt--;}
    cout<<endl;

}


    return 0;
}