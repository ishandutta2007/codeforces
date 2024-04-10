#include<bits/stdc++.h>
using namespace std;
int X[300300];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        	cin>>X[i];
        bool IIII=false;
        for(int i=0;i<N;i++)
        	if(X[i]<i)
        	{
        		IIII=true;
        		bool OK=true;
        		for(int j=i-1;j<N;j++)
        			if(X[j]<(N-j-1))
        				OK=false;
        		if(OK)
        			puts("Yes");
        		else	puts("No");
        		break;
			}
		if(!IIII)
			puts("Yes");
    }
    return 0;
}