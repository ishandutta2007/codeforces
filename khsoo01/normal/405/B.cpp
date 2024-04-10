#include<bits/stdc++.h>
using namespace std;
int n, ans, pr;
char ipt[3005];
bool phase;

int main()
{
    scanf("%d%s",&n,&ipt);
    int fsr, lsl;
    for(fsr=0;fsr<n;fsr++) if(ipt[fsr]=='R') break;
    for(int i=fsr;i--;) {
        if(ipt[i]=='L') break;
        ans++;
    }
    int cnt = 0;
    for(int i=fsr+1;i<n;i++) {
        if(!phase) {
            if(ipt[i]=='L') {
                phase = true;
                if(cnt%2) ans++;
                cnt = 0;
                pr++;
            }
            else cnt++;
        }
        else {
            if(ipt[i]=='R') phase = false;
            else ans++;
        }
    }
    printf("%d",ans);
}