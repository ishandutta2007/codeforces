/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int len_ans;
char ans[1000001];

void LongestPalindromicPrefix(string str)
{
    // Create temporary string
    string temp = str + '?';

    // Reverse the string str
    reverse(str.begin(), str.end());

    // Append string str to temp
    temp += str;

    // Find the length of string temp
    int n = temp.length();

    // lps[] array for string temp
    int lps[n];

    // Intialise every value with zero
    fill(lps, lps + n, 0);

    // Iterate the string temp
    for (int i = 1; i < n; i++) {

        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];

        // Calculate length for i+1
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }

        // If character at current index
        // len are same then increament
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }

        // Update the length at current
        // index to len
        lps[i] = len;
    }

    // Print the palindromic string of
    // max_len
    string val = temp.substr(0, lps[n - 1]);
    if(val.size()>len_ans)
    {
        len_ans=val.size();
        for(int i=0;i<val.size();i++) ans[i]=val[i];
    }
}

void solve()
{
    string s;
    cin>>s;

    int n=s.size();
    len_ans=0;

    int strt=0, nd=n-1;
    while(strt<=nd && s[strt]==s[nd]) { strt++; nd--; }

    if(strt>nd) { cout<<s<<endl; return; }

    string a=s.substr(strt, nd-strt+1);

    LongestPalindromicPrefix(a);

    reverse(a.begin(), a.end());
    LongestPalindromicPrefix(a);

    for(int i=0;i<strt;i++) cout<<s[i];
    for(int i=0;i<len_ans;i++) cout<<ans[i];
    for(int i=nd+1;i<n;i++) cout<<s[i];
    cout<<endl;
}

int32_t main()
{
    /*
    string s;
    cin>>s;
    string a = s.substr(10, 1);
    cout<<a<<endl;
    return 0;
    */

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}