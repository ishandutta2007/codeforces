#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[15000];
int b[15000];
int main()
{
    int n,flag =1;
    int cnt = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<floor((double)a[i]/2)<<" "<<ceil((double)a[i]/2)<<endl;
        b[i]=a[i]/2;
        //cout<<b[i]<<endl;
        cnt += b[i];
    }
    if(cnt == 0){
        for(int i=1;i<=n;i++){
            cout<<b[i]<<endl;
        }
        return 0;
    }
    if(cnt > 0){
        for(int i=1;i<=n;i++){
            if(a[i]%2 != 0 && cnt > 0 && a[i] < 0){
                cout<<b[i] - 1<<endl;
                cnt--;
            }else{
                cout<<b[i]<<endl;
            }
        }
        return 0;
    }
    if(cnt < 0){
        cnt = -cnt;
        for(int i=1;i<=n;i++){
            if(a[i]%2 != 0 && cnt > 0 && a[i] > 0){
                cout<<b[i] + 1<<endl;
                cnt--;
            }else{
                cout<<b[i]<<endl;
            }
        }
        return 0;
    }



    return 0;
}