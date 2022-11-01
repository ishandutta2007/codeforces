#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int i;
    char j;
    int l;
    int k;
    int t=0;
    cin>>l>>k;
    cin>>s;
    s='a'+s+'a';
    for (int i1=1;i1<l;i1++){
        if(s[i1]=='.'&&s[i1+1]==s[i1]) t++;
    }
    for (int i1=0;i1<k;i1++){
        cin>>i>>j;
        if (s[i]=='.'&&j!='.') {
            s[i]=j;
            if (s[i-1]=='.'&&t!=0){t--;}
            if (s[i+1]=='.'&&t!=0){t--;}
        }
        if (s[i]!='.'&&j=='.'){
            s[i]=j;
            if (s[i-1]=='.'){t++;}
            if (s[i+1]=='.'){t++;}
        }
        cout<<t<<endl;
    }
    return 0;
}