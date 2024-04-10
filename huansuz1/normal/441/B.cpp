#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;


long long a[3234],b[3234],n,m,ans,q;

int main(){
cin>>n>>m;
for (int i=1; i<=n; i++){
cin>>a[i]>>q;
b[a[i]]+=q;
}
for (int i=1; i<=3001; i++){
int x=m;

if (b[i-1]>=x) {b[i-1]-=x; ans+=x; x=0;} else{
ans+=b[i-1];
x-=b[i-1];
b[i-1]=0;
}

if (b[i]>=x) {ans+=x; b[i]-=x; x=0;} else {
ans+=b[i];
b[i]=0;
x=0;
}

 
 
}


		    			
cout<<ans;    	

}