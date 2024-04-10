#include<bits/stdc++.h>

using namespace std;

int a[2000];

int main(){
    int n;
    cin>>n;
    a[0] = a[n+1] = 0;
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int tot = 0;
    for(int i = 1; i <= n; i++)
        if (!a[i] && a[i-1] && a[i+1])
            a[i] = 1;
    for(int i = 1; i <= n; i++)
        tot+=a[i];
    cout<<tot<<endl;
    return 0;
}