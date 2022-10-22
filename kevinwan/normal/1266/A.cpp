#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        string s;
        cin>>s;
        int sum=0;
        int zero=0,even=0;
        for(char c:s){
            c-='0';
            sum+=c;
            if(c==0)zero++;
            if(c%2==0)even++;
        }
        if(zero>=1&&even>=2&&sum%3==0)printf("red\n");
            else printf("cyan\n");
    }
}