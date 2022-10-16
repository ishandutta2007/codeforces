#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool arr[n+5];
    int para[n+5][2];
    char c;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='0')arr[i]=false;
        else {
            arr[i]=true;
            cnt++;
        }
    }
    int maxcnt=cnt;
    for(int i=0;i<n;i++){
        cin>>para[i][0]>>para[i][1];
    }
    for(int t=1;t<=100000;t++){
        for(int i=0;i<n;i++){
            if(para[i][1]<=t&&(t-para[i][1])%para[i][0]==0){
                if(arr[i]==1){
                    arr[i]=0;
                    cnt--;
                }
                else {
                    arr[i]=1;
                    cnt++;
                }
            }
        }
        maxcnt=max(maxcnt,cnt);
    }
    cout<<maxcnt<<endl;
    return 0;
}