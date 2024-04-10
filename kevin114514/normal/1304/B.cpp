#include<bits/stdc++.h>
using namespace std;
vector<string> V;
string A,B;
int main()
{
    int N,K;
    cin>>N>>K;
    while(N--)
    {
        string S;
        cin>>S;
        V.push_back(S);
    }
    while((int)(V.size()))
    {
    	int i=0;
        string S=V[i];
        reverse(S.begin(),S.end());
        bool OK=true;
        for(int j=0;j<V.size();j++)
            if(i!=j&&V[j]==S)
            {
                OK=false;
                A+=V[i];
                V.erase(V.begin()+j);
                break;
            }
        if(OK)
            if(V[i]==S)
            	B=S;
        V.erase(V.begin()+i);
    }
    string C=A;
    reverse(C.begin(),C.end());
    A=A+B+C;
    cout<<A.length()<<endl<<A;
    return 0;
}