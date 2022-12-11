#include<iostream>
#include<string>

using namespace std;

int main() {

string s;

long long u1, u2, u3_0=0, u3;
int met1[30], met2[30], met[30], d1, d2, i, d=0, k, met0[30], d0=0;

cin>>s;

for (i=0; i<26; i++)
    met[i]=0;

for (i=0; i<s.size(); i++)
if (met[s[i]-'a']==0) {met[s[i]-'a']=1; d++;}

for (i=0; i<26; i++)
    met0[i]=0;

cout<<d<<endl;

for (k=1; k<=d; k++) {
long long ans;
    while (d0<k) {u3_0++; met0[s[u3_0-1]-'a']++; if (met0[s[u3_0-1]-'a']==1) d0++;}
    u2=0; u1=0; d2=d0; d1=d0;
    for (i=0; i<26; i++) {met1[i]=met0[i]; met2[i]=met0[i];}
    while (d2==k) {u2++; met2[s[u2-1]-'a']--; if (met2[s[u2-1]-'a']==0) {met2[s[u2-1]-'a']=1; u2--; break;} }
    ans=u2-u1+1;

    for (u3=u3_0+1; u3<=s.size(); u3++) {
        if (met2[s[u3-1]-'a']==0) {
                met2[s[u3-1]-'a']=1;
                met1[s[u3-1]-'a']=1;
                d2++;
                d1++;
                u1=u2;
                for (i=0; i<26; i++) met1[i]=met2[i];
                while (d1>k) {
                        u1++;
                        met1[s[u1-1]-'a']--;
                        if (met1[s[u1-1]-'a']==0) d1--;
                        }
                u2=u1;
                for (i=0; i<26; i++) met2[i]=met1[i];
                d2=d1;
                while (d2==k) {u2++; met2[s[u2-1]-'a']--; if (met2[s[u2-1]-'a']==0) {met2[s[u2-1]-'a']=1; u2--; break;} }
                ans+=u2-u1+1;}
            else {
                met2[s[u3-1]-'a']++;
                met1[s[u3-1]-'a']++;
                while (d2==k) {
                    u2++;
                    met2[s[u2-1]-'a']--;
                    if (met2[s[u2-1]-'a']==0) {met2[s[u2-1]-'a']=1; u2--; break;}
                }
                ans+=u2-u1+1;
            }
        }
        cout<<ans<<endl;

}

}