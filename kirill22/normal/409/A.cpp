 #include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;



int main() {
    int n, k,ans=0;
    string s,s1;
    cin >> s >> s1;
    for(int i=0;i<s.size();i+=2){
        if (s[i]=='[' && s1[i]=='['){
                        ans+=0;
        }
        if (s[i]=='[' && s1[i]=='('){
                        ans+=1;
        }
        if (s[i]=='[' && s1[i]=='8'){
                        ans-=1;
        }
        if (s[i]=='8' && s1[i]=='8'){
                        ans+=0;
        }
        if (s[i]=='8' && s1[i]=='['){
                        ans+=1;
        }
        if (s[i]=='8' && s1[i]=='('){
                        ans-=1;
        }
        if (s[i]=='(' && s1[i]=='('){
                        ans+=0;
        }
        if (s[i]=='(' && s1[i]=='8'){
                        ans+=1;
        }
        if (s[i]=='(' && s1[i]=='['){
                        ans-=1;
        }
    }

    if (ans>0){
        cout << "TEAM 1 WINS";
    }
    else if(ans==0){
        cout << "TIE";
    }
    else{
        cout << "TEAM 2 WINS";
    }
   /* int n,k;
   cin >> n >> k;
    cout << n+k;*/






    return 0;
}