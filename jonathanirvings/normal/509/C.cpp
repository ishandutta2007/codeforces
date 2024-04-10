#include<bits/stdc++.h>
using namespace std;
int n,b[305], fl[305] = {0};
vector<string> ans;
string f[305];
string reverse(string x){
    string ret = "";
    int l = x.length();
    for(int i=l-1; i>=0;i--) ret += x[i];
    return ret;
}

string first(int x){
    string ret = "";
    while(x){
        for(int i=9; i>=1; i--) if(x >= i) {
            x -= i;
            ret += i+'0';
            break;
        }
    }
    return reverse(ret);
}

string adv(string s, int t){
    int l = s.length(), ch = 0;
    for(int i=l-1; i>0;i--)
        if(s[i-1] != '9' && s[i] != '0'){
            ch = i;
            s[i-1]++;
            break;
        }
    if(!ch) {
        s = '1' + s;
        ch = 1;
        l++;
    }
    for(int i=0; i<ch;i++) t -= (s[i]-'0');
    string ret = "";
    for(int i=0; i<ch;i++) ret += s[i];
    for(int i=0; i< l-ch-fl[t]; i++) ret += '0';

    return ret + f[t];
}


void solve(int x){
    string ret = "";
    int l = ans[x-1].length();
    if(b[x] <= b[x-1]){
        if(b[x] < ans[x-1][0]-'0'){
            ret += '1';
            for(int i=0; i<l-fl[b[x]-1]; i++) ret += '0';
            ret += f[b[x]-1];
            ans[x] = ret;
        }
        else{
            for(int i=0,r=b[x]; i<l;i++){
                if(!r) ret += '0';
                else if(r < ans[x-1][i]-'0'){
                    ret += r+'0';
                    r = 0;
                }
                else{
                    ret += ans[x-1][i];
                    r-=(ans[x-1][i]-'0');
                }
            }

            ans[x] = adv(ret, b[x]);
        }
    }
    else{
        int d  = b[x] - b[x-1];
        if(9*l < b[x]){
            ans[x] = first(b[x]);
        }
        else{
            ans[x] = ans[x-1];
            for(int i=l-1; i>=0 && d;){
                while(ans[x][i] < '9'){
                    ans[x][i]++;
                    d--;
                    if(!d) break;
                }
                i--;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<305;i++) { f[i] = first(i); fl[i] = f[i].length(); }
    for(int i=0; i<n;i++) scanf("%d", &b[i]);
    for(int i=0; i<n;i++) ans.push_back(f[b[i]]);

    cout << ans[0] << endl;
    for(int i=1; i<n;i++){
        solve(i);
        cout << ans[i] << endl;
    }

    return 0;
}