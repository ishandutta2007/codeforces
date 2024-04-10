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
#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;

int k,n,w,a[4123],s,ans;
map<int,int> ma;
                      
int main(){
    cin>>n;
    for (int i=0; i<n; i++){
        cin>>a[i];          
        ma[a[i]]++; 
    }
    for (int i=1; i<=n; i++){

        if (ma[i]>1) {
            while(ma[i]!=1){
                for (int j=i; j<10000; j++)
                    if (ma[j]==0) {ma[j]=1;  break; }else ans++;
                ma[i]--;
            }
        }
    }
    cout<<ans;

            return 0;


}