#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string S;
		cin>>S;
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<S.length();i++)
			cnt[S[i]-'a']++;
		int mn=1e9;
		for(int i=0;i<26;i++)
			if(cnt[i])
				mn=min(mn,cnt[i]);
		if(mn==1)
		{
			string T;
			for(int i=0;i<26;i++)
				if(cnt[i]==1)
				{
					T+=(char)(i+'a');
					break;
				}
			string nT;
			for(int i=0;i<S.length();i++)
				if(S[i]!=T[0])
					nT+=S[i];
			srt(nT);
			cout<<T<<nT<<endl;
		}
		else
		{
			int fst=0;
			for(int i=0;i<26;i++)
				if(cnt[i])
				{
					fst=i;
					break;
				}
			int others=S.length()-cnt[fst];
			int mxplace=(cnt[fst]-1+others)/(others+1);
			if(!mxplace)
				mxplace=1;
			if(mxplace>1)
			{
				int Cnt=0;
				for(int i=0;i<26;i++)
					if(cnt[i])
						Cnt++;
				if(Cnt<=2)
				{
					cout<<(char)(fst+'a');
					for(int i=0;i<S.length();i++)
						if(S[i]!=fst+'a')
							cout<<S[i];
					for(int i=1;i<cnt[fst];i++)
						cout<<(char)(fst+'a');
				}
				else
				{
					int snd=-1,trd;
					for(int i=fst+1;i<26;i++)
						if(cnt[i])
						{
							if(snd!=-1)
							{
								trd=i;
								break;
							}
							else	snd=i;
						}
					cout<<(char)(fst+'a');
					cout<<(char)(snd+'a');
					for(int i=1;i<cnt[fst];i++)
						cout<<(char)(fst+'a');
					cout<<(char)(trd+'a');
					cnt[snd]--;
					cnt[trd]--;
					for(int i=fst+1;i<26;i++)
						for(int j=0;j<cnt[i];j++)
							cout<<(char)(i+'a');
				}
				puts("");
				continue;
			}
			string T;
			for(int i=0;i<S.length();i++)
				if(S[i]!=fst+'a')
					T+=S[i];
			srt(T);
//			cout<<T<<endl;
			for(int i=0;i<=mxplace;i++)
				cout<<(char)(fst+'a');
			cnt[fst]-=mxplace+1;
			int l=0;
			while(cnt[fst]>0)
			{
				cout<<T[l++];
				for(int i=0;i<min(cnt[fst],mxplace);i++)
					cout<<(char)(fst+'a');
				cnt[fst]-=mxplace;
			}
			for(;l<T.length();l++)
				cout<<T[l];
			puts("");
		}
	}
	return 0;
}
//tutttttttttttttttttvuuuuuuuuvvvv
//ttutututututututututvtvtvtvtvt