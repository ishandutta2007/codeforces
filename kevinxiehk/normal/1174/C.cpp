#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
    cin>>n;
    int arr[n+5];
    bool used=false;
    int now=0;
    for(int i=0;i<=n+1;i++)arr[i]=-1;
    for(int i=2;i<=n;i++){
        used=false;
        for(int j=i;j<=n;j+=i){
            if(arr[j]==-1){
                if(!used)now++;
                used=true;
                arr[j]=now;
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<arr[i];
        if(i!=n)cout<<" ";
        else cout<<endl;
    }
	return 0;
}