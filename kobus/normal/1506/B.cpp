#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        int n,k;
        cin>>n>>k;
        char s[n];
        for(int i=0;i<n;i++)cin>>s[i];
        int last;
        int lastfound;
        int num=0;
        bool achou=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(achou==0){
                    num++;
                    last=i;
                    lastfound=i;
                    achou=1;
                    s[i]='X';
                }
                else if(i-last>k){
                    num++;
                    s[lastfound]='X';
                    last=lastfound;
                    lastfound=i;
                }
                else{
                    lastfound=i;
                }
            }
        }
        //cout<<lastfound<<" "<<last<<endl;
        if(lastfound!=last)num++;
        s[lastfound]='X';
        cout<<num<<endl;
    }
 
    return 0;
}