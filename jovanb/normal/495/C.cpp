#include <bits/stdc++.h>

using namespace std;
long bro[100000];
long brz[100000];
char str[100000];
queue <long> kju;
int main()
{
    cin>>str;
    long n=strlen(str),i,x,br=0,brt=0,brtr=0,j;
    if(str[0]=='(')bro[0]=1;
    else{cout<<-1;return 0;}
    for(i=1;i<n;i++){
        bro[i]=bro[i-1];
        brz[i]=brz[i-1];
        if(str[i]=='(')bro[i]++;
        else if(str[i]==')')brz[i]++;
        else brt++;
        if(brt==0 && brz[i]>bro[i]){cout<<-1;return 0;}
    }
    for(i=1;i<n;i++){
        if(str[i]=='#'){
            brtr++;
            if(brtr!=brt){
                x=bro[i]-(brz[i]+br);
                if(x<=0){cout<<-1;return 0;}
                else{
                    kju.push(1);
                    br+=1;
                }
            }
            else{
                x=bro[n-1]-(brz[n-1]+br);
                if(x<=0){cout<<-1;return 0;}
                else kju.push(x);
                br+=x;
                for(j=i;j<n;j++){
                    if(brz[j]+br>bro[j]){cout<<-1;return 0;}
                }
            }
        }
    }
    while(kju.empty()==false){
        cout<<kju.front()<<endl;
        kju.pop();
    }
    return 0;
}