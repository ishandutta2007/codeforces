#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
void findLongestPalindromicString(string text) 
{ 
	int N = text.size(); 
	if(N == 0) 
		return; 
	N = 2*N + 1; //Position count 
	int L[N]; //LPS Length Array 
	L[0] = 0; 
	L[1] = 1; 
	int C = 1; //centerPosition 
	int R = 2; //centerRightPosition 
	int i = 0; //currentRightPosition 
	int iMirror; //currentLeftPosition 
	int expand = -1; 
	int diff = -1; 
	int maxLPSLength = 0; 
	int maxLPSCenterPosition = 0; 
	int start = -1; 
	int end = -1; 
	
	//Uncomment it to print LPS Length array 
	//printf("%d %d ", L[0], L[1]); 
	for (i = 2; i < N; i++) 
	{ 
		//get currentLeftPosition iMirror for currentRightPosition i 
		iMirror = 2*C-i; 
		//Reset expand - means no expansion required 
		expand = 0; 
		diff = R - i; 
		//If currentRightPosition i is within centerRightPosition R 
		if(diff > 0) 
		{ 
			if(L[iMirror] < diff) // Case 1 
				L[i] = L[iMirror]; 
			else if(L[iMirror] == diff && i == N-1) // Case 2 
				L[i] = L[iMirror]; 
			else if(L[iMirror] == diff && i < N-1) // Case 3 
			{ 
					L[i] = L[iMirror]; 
					expand = 1; // expansion required 
			} 
			else if(L[iMirror] > diff) // Case 4 
			{ 
				L[i] = diff; 
				expand = 1; // expansion required 
			} 
		} 
		else
		{ 
			L[i] = 0; 
			expand = 1; // expansion required 
		} 
		
		if (expand == 1) 
		{ 
			//Attempt to expand palindrome centered at currentRightPosition i 
			//Here for odd positions, we compare characters and 
			//if match then increment LPS Length by ONE 
			//If even position, we just increment LPS by ONE without 
			//any character comparison 
			while (((i + L[i]) < N && (i - L[i]) > 0) && 
				( ((i + L[i] + 1) % 2 == 0) || 
				(text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] ))) 
			{ 
				L[i]++; 
			} 
		} 

		if((L[i] > maxLPSLength) && ( ((i-L[i])/2)==0 ||(((i-L[i])/2)+L[i]-1)==(N/2-1)))
		{ 
			maxLPSLength = L[i]; 
			maxLPSCenterPosition = i; 
		} 

		// If palindrome centered at currentRightPosition i 
		// expand beyond centerRightPosition R, 
		// adjust centerPosition C based on expanded palindrome. 
		if (i + L[i] > R) 
		{ 
			C = i; 
			R = i + L[i]; 
		} 
		//Uncomment it to print LPS Length array 
		//printf("%d ", L[i]); 
	} 
	//printf("\n"); 
	start = (maxLPSCenterPosition - maxLPSLength)/2; 
	end = start + maxLPSLength - 1; 
	for(i=start; i<=end; i++) 
		cout<<text[i];
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		string s,r;
		cin>>s;
		int n;
		n=s.size();
		int c=0;
		while(c<=(n-c-1) && s[c]==s[n-c-1])
		{
			cout<<s[c];
			c++;
		}
		r=s.substr(c,n-2*c);
//		cout<<r<<'\n';
//		cout<<c;
		if(c<=(n-c-1))
		findLongestPalindromicString(r);
//		cout<<'*';
		int o=0;
		if(c>(n-c-1) && n%2==1)
		o=1;
		FOR(i,o,c)
		{
			
			cout<<s[n-c+i];
		}
		cout<<'\n';
	}
	return 0;
}