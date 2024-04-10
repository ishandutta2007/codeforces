#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#define pb push_back
#define mk make_pair
#define inf  (1ll << 55)
#define f first
#define s second
#define MAXN (1 << 20)
#define ll long long;

using namespace std;

int n,a[123456],b[123456],z;

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);   
        b[i]=a[i];  
    }
    sort(b,b+n);
    for(int i=0; i<n; i++)
        if(a[i]!=b[i])
            z++;
    if(!z||z==2)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;

}