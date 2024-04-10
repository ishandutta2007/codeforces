/*
Hey, you!
Out there in the cold
Getting lonely, getting old.
Can you feel me?

Hey, you!
Standing in the aisles
With itchy feet and fading smiles.
Can you feel me?

Hey, you!
Don't help them to bury the light.
Don't give in without a fight.

Hey, you!
Out there on your own
Sitting naked by the phone.
Would you touch me?

Hey, you!
With your ear against the wall
Waiting for someone to call out.
Would you touch me?

Hey, you!
Would you help me to carry the stone?
Open your heart, I'm coming home

But it was only fantasy.
The wall was too high as you can see.
No matter how he tried he could not break free.
And the worms ate into his brain.

Hey, you!
Out there on the road,
Always doing what you're told.
Can you help me?

Hey, you!
Out there beyond the wall,
Breaking bottles in the hall.
Can you help me?

Hey, you!
Don't tell me there's no hope at all.
Together we stand,
Divided we fall.
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

// 0 for expr, 1 for term, 2 for func

vector<pair<string,pair<int,string > > > primitives[1200];

string ans[1<<10];
int done_cnt;

int min_len[500][50];

int get_mask(string st){
	int res=0;
	for (int i=0;i<st.size();i++){
		res=res*2+st[i]-48;
	}
	return res;
}

bool worse(string a,string b){
	if (a.size()==0)
		return true;
	if (a.size()!=b.size())
		return a.size()>b.size();
	return a>b;
}

string AANS[500][5];

void update2(pair<string,pair<int,string > > P){
	for (int jj=0;jj<=P.second.first;jj++){
		pair<string,pair<int,string > > p=P;
		p.second.first=jj;
		int cur_mask=get_mask(p.second.second);
		if (!worse(AANS[cur_mask][p.second.first],p.first))
			continue;;
		AANS[cur_mask][p.second.first]=p.first;

		if (ans[cur_mask].size()==0)
			done_cnt++;
		if (worse(ans[cur_mask],p.first))
			ans[cur_mask]=p.first;
		primitives[p.first.size()].push_back(p);
	}
}

pair<string,pair<int,string > >apply_neg(pair<string,pair<int,string > > p){
	p.first="!"+p.first;
	p.second.first=2;
	for (int i=0;i<p.second.second.size();i++){
		int here=p.second.second[i]-'0';
		here^=1;
		p.second.second[i]=here+'0';
	}
	return p;
}

pair<string,pair<int,string > >apply_brackets(pair<string,pair<int,string > > p){
	p.first="("+p.first+")";
	p.second.first=2;
	return p;
}

pair<string,pair<int,string > >apply_and(pair<string,pair<int,string > > p1,pair<string,pair<int,string> > p2){
	pair<string,pair<int,string > > p;
	p.first=p1.first+"&"+p2.first;
	p.second.first=1;
	p.second.second=p1.second.second;

	for (int i=0;i<8;i++){
		int a=p1.second.second[i]-'0';
		int b=p2.second.second[i]-'0';
		a&=b;
		p.second.second[i]=a+'0';
	}
	return p;
}

pair<string,pair<int,string > >apply_or(pair<string,pair<int,string > > p1,pair<string,pair<int,string> > p2){
	pair<string,pair<int,string > > p;
	p.first=p1.first+"|"+p2.first;
	p.second.first=0;
	p.second.second=p1.second.second;

	for (int i=0;i<8;i++){
		int a=p1.second.second[i]-'0';
		int b=p2.second.second[i]-'0';
		a|=b;
		p.second.second[i]=a+'0';
	}
	return p;
}

map<string,string> ANS;

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(0);
//	cin.tie(0);

	/*for (int i=0;i<256;i++){
		ans[i]="";
		for (int j=0;j<=4;j++){
			min_len[i][j]=1e9;
		}
	}

	update2(make_pair("x",make_pair(2,"00001111")));
	update2(make_pair("y",make_pair(2,"00110011")));
	update2(make_pair("z",make_pair(2,"01010101")));

	for (int i=1;i<=30;i++){
		cout<<i<<"%"<<primitives[i].size()<<" "<<done_cnt<<endl;
		//cin.get();
		for (int j=0;j<primitives[i].size();j++){
			//update_res(primitives[i][j]);
			int cur_mask=get_mask(primitives[i][j].second.second);
			pair<string,pair<int,string> > p=primitives[i][j];
			if (worse(p.first,AANS[cur_mask][p.second.first]))
				continue;
			// !
			if (primitives[i][j].second.first==2){
				pair<string,pair<int,string> > temp=apply_neg(primitives[i][j]);
				update2(temp);
			}
			// brackets
			if (primitives[i][j].second.first==0){
				pair<string,pair<int,string> > temp=apply_brackets(primitives[i][j]);
				update2(temp);
			}

			// and
			for (int q=0;q<=i;q++){
				for (int w=0;w<primitives[q].size();w++){
					pair<string,pair<int,string> > p1=primitives[i][j];
					pair<string,pair<int,string> > p2=primitives[q][w];
					if (p1.second.first!=1||p2.second.first!=2);
					else
					{
						pair<string,pair<int,string > > temp=apply_and(p1,p2);
						update2(temp);
					}
					if (p1==p2)
						continue;
					swap(p1,p2);
					if (p1.second.first!=1||p2.second.first!=2);
					else
					{
						pair<string,pair<int,string > > temp=apply_and(p1,p2);
						update2(temp);
					}
				}
			}
			// or,
			for (int q=0;q<=i;q++){
				for (int w=0;w<primitives[q].size();w++){
					pair<string,pair<int,string> > p1=primitives[i][j];
					pair<string,pair<int,string> > p2=primitives[q][w];
					if (p1.second.first!=0||p2.second.first!=1);
					else
						{pair<string,pair<int,string > > temp=apply_or(p1,p2);
						update2(temp);}
					swap(p1,p2);
					if (p1==p2)
						continue;
					if (p1.second.first!=0||p2.second.first!=1);
					else
						{pair<string,pair<int,string > > temp=apply_or(p1,p2);
						update2(temp);}

				}
			}
		}
		//cout<<i<<"@"<<done_cnt<<endl;
		//if (done_cnt==256)
		//	break;
	}

	int total_len=0;

	for (int i=0;i<256;i++){
		string temp="";
		for (int j=7;j>=0;--j){
			if (i&(1<<j))
				temp+="1";
			else
				temp+="0";
		}
		total_len+=ans[i].size();
		cout<<"ANS[\""<<temp<<"\"]="<<"\""<<ans[i]<<"\";"<<endl;
	}

	cout<<total_len<<endl;

	*/
	ANS["00000000"]="!x&x";
	ANS["00000001"]="x&y&z";
	ANS["00000010"]="!z&x&y";
	ANS["00000011"]="x&y";
	ANS["00000100"]="!y&x&z";
	ANS["00000101"]="x&z";
	ANS["00000110"]="!y&x&z|!z&x&y";
	ANS["00000111"]="(y|z)&x";
	ANS["00001000"]="!y&!z&x";
	ANS["00001001"]="!y&!z&x|x&y&z";
	ANS["00001010"]="!z&x";
	ANS["00001011"]="!z&x|x&y";
	ANS["00001100"]="!y&x";
	ANS["00001101"]="!y&x|x&z";
	ANS["00001110"]="!(y&z)&x";
	ANS["00001111"]="x";
	ANS["00010000"]="!x&y&z";
	ANS["00010001"]="y&z";
	ANS["00010010"]="!x&y&z|!z&x&y";
	ANS["00010011"]="(x|z)&y";
	ANS["00010100"]="!x&y&z|!y&x&z";
	ANS["00010101"]="(x|y)&z";
	ANS["00010110"]="!x&y&z|!y&x&z|!z&x&y";
	ANS["00010111"]="(x|y)&z|x&y";
	ANS["00011000"]="!x&y&z|!y&!z&x";
	ANS["00011001"]="!y&!z&x|y&z";
	ANS["00011010"]="!x&y&z|!z&x";
	ANS["00011011"]="!z&x|y&z";
	ANS["00011100"]="!x&y&z|!y&x";
	ANS["00011101"]="!y&x|y&z";
	ANS["00011110"]="!(y&z)&x|!x&y&z";
	ANS["00011111"]="x|y&z";
	ANS["00100000"]="!x&!z&y";
	ANS["00100001"]="!x&!z&y|x&y&z";
	ANS["00100010"]="!z&y";
	ANS["00100011"]="!z&y|x&y";
	ANS["00100100"]="!x&!z&y|!y&x&z";
	ANS["00100101"]="!x&!z&y|x&z";
	ANS["00100110"]="!y&x&z|!z&y";
	ANS["00100111"]="!z&y|x&z";
	ANS["00101000"]="!(!x&!y|x&y|z)";
	ANS["00101001"]="!(!x&!y|x&y|z)|x&y&z";
	ANS["00101010"]="!z&(x|y)";
	ANS["00101011"]="!z&(x|y)|x&y";
	ANS["00101100"]="!x&!z&y|!y&x";
	ANS["00101101"]="!x&!z&y|!y&x|x&z";
	ANS["00101110"]="!y&x|!z&y";
	ANS["00101111"]="!z&y|x";
	ANS["00110000"]="!x&y";
	ANS["00110001"]="!x&y|y&z";
	ANS["00110010"]="!(x&z)&y";
	ANS["00110011"]="y";
	ANS["00110100"]="!x&y|!y&x&z";
	ANS["00110101"]="!x&y|x&z";
	ANS["00110110"]="!(x&z)&y|!y&x&z";
	ANS["00110111"]="x&z|y";
	ANS["00111000"]="!x&y|!y&!z&x";
	ANS["00111001"]="!x&y|!y&!z&x|y&z";
	ANS["00111010"]="!x&y|!z&x";
	ANS["00111011"]="!z&x|y";
	ANS["00111100"]="!x&y|!y&x";
	ANS["00111101"]="!x&y|!y&x|x&z";
	ANS["00111110"]="!(x&z)&y|!y&x";
	ANS["00111111"]="x|y";
	ANS["01000000"]="!x&!y&z";
	ANS["01000001"]="!x&!y&z|x&y&z";
	ANS["01000010"]="!x&!y&z|!z&x&y";
	ANS["01000011"]="!x&!y&z|x&y";
	ANS["01000100"]="!y&z";
	ANS["01000101"]="!y&z|x&z";
	ANS["01000110"]="!y&z|!z&x&y";
	ANS["01000111"]="!y&z|x&y";
	ANS["01001000"]="!(!x&!z|x&z|y)";
	ANS["01001001"]="!(!x&!z|x&z|y)|x&y&z";
	ANS["01001010"]="!x&!y&z|!z&x";
	ANS["01001011"]="!x&!y&z|!z&x|x&y";
	ANS["01001100"]="!y&(x|z)";
	ANS["01001101"]="!y&(x|z)|x&z";
	ANS["01001110"]="!y&z|!z&x";
	ANS["01001111"]="!y&z|x";
	ANS["01010000"]="!x&z";
	ANS["01010001"]="!x&z|y&z";
	ANS["01010010"]="!x&z|!z&x&y";
	ANS["01010011"]="!x&z|x&y";
	ANS["01010100"]="!(x&y)&z";
	ANS["01010101"]="z";
	ANS["01010110"]="!(x&y)&z|!z&x&y";
	ANS["01010111"]="x&y|z";
	ANS["01011000"]="!x&z|!y&!z&x";
	ANS["01011001"]="!x&z|!y&!z&x|y&z";
	ANS["01011010"]="!x&z|!z&x";
	ANS["01011011"]="!x&z|!z&x|x&y";
	ANS["01011100"]="!x&z|!y&x";
	ANS["01011101"]="!y&x|z";
	ANS["01011110"]="!(x&y)&z|!z&x";
	ANS["01011111"]="x|z";
	ANS["01100000"]="!(!y&!z|x|y&z)";
	ANS["01100001"]="!(!y&!z|x|y&z)|x&y&z";
	ANS["01100010"]="!x&!y&z|!z&y";
	ANS["01100011"]="!x&!y&z|!z&y|x&y";
	ANS["01100100"]="!x&!z&y|!y&z";
	ANS["01100101"]="!x&!z&y|!y&z|x&z";
	ANS["01100110"]="!y&z|!z&y";
	ANS["01100111"]="!y&z|!z&y|x&y";
	ANS["01101000"]="!(!x&!y|x&y|z)|!x&!y&z";
	ANS["01101001"]="!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
	ANS["01101010"]="!x&!y&z|!z&(x|y)";
	ANS["01101011"]="!x&!y&z|!z&(x|y)|x&y";
	ANS["01101100"]="!x&!z&y|!y&(x|z)";
	ANS["01101101"]="!x&!z&y|!y&(x|z)|x&z";
	ANS["01101110"]="!y&(x|z)|!z&y";
	ANS["01101111"]="!y&z|!z&y|x";
	ANS["01110000"]="!x&(y|z)";
	ANS["01110001"]="!x&(y|z)|y&z";
	ANS["01110010"]="!x&z|!z&y";
	ANS["01110011"]="!x&z|y";
	ANS["01110100"]="!x&y|!y&z";
	ANS["01110101"]="!x&y|z";
	ANS["01110110"]="!(x&y)&z|!z&y";
	ANS["01110111"]="y|z";
	ANS["01111000"]="!x&(y|z)|!y&!z&x";
	ANS["01111001"]="!x&(y|z)|!y&!z&x|y&z";
	ANS["01111010"]="!x&(y|z)|!z&x";
	ANS["01111011"]="!x&z|!z&x|y";
	ANS["01111100"]="!x&(y|z)|!y&x";
	ANS["01111101"]="!x&y|!y&x|z";
	ANS["01111110"]="!x&y|!y&z|!z&x";
	ANS["01111111"]="x|y|z";
	ANS["10000000"]="!(x|y|z)";
	ANS["10000001"]="!(x|y|z)|x&y&z";
	ANS["10000010"]="!(!x&y|!y&x|z)";
	ANS["10000011"]="!(x|y|z)|x&y";
	ANS["10000100"]="!(!x&z|!z&x|y)";
	ANS["10000101"]="!(x|y|z)|x&z";
	ANS["10000110"]="!(!x&y|!y&x|z)|!y&x&z";
	ANS["10000111"]="!(x|y|z)|(y|z)&x";
	ANS["10001000"]="!y&!z";
	ANS["10001001"]="!y&!z|x&y&z";
	ANS["10001010"]="!(!x&y|z)";
	ANS["10001011"]="!y&!z|x&y";
	ANS["10001100"]="!(!x&z|y)";
	ANS["10001101"]="!y&!z|x&z";
	ANS["10001110"]="!(!x&y|z)|!y&x";
	ANS["10001111"]="!y&!z|x";
	ANS["10010000"]="!(!y&z|!z&y|x)";
	ANS["10010001"]="!(x|y|z)|y&z";
	ANS["10010010"]="!(!x&y|!y&x|z)|!x&y&z";
	ANS["10010011"]="!(x|y|z)|(x|z)&y";
	ANS["10010100"]="!(!x&z|!z&x|y)|!x&y&z";
	ANS["10010101"]="!(x|y|z)|(x|y)&z";
	ANS["10010110"]="!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
	ANS["10010111"]="!(x|y|z)|(x|y)&z|x&y";
	ANS["10011000"]="!x&y&z|!y&!z";
	ANS["10011001"]="!y&!z|y&z";
	ANS["10011010"]="!(!x&y|z)|!x&y&z";
	ANS["10011011"]="!(!x&y|z)|y&z";
	ANS["10011100"]="!(!x&z|y)|!x&y&z";
	ANS["10011101"]="!(!x&z|y)|y&z";
	ANS["10011110"]="!(!x&y|z)|!x&y&z|!y&x";
	ANS["10011111"]="!y&!z|x|y&z";
	ANS["10100000"]="!x&!z";
	ANS["10100001"]="!x&!z|x&y&z";
	ANS["10100010"]="!(!y&x|z)";
	ANS["10100011"]="!x&!z|x&y";
	ANS["10100100"]="!x&!z|!y&x&z";
	ANS["10100101"]="!x&!z|x&z";
	ANS["10100110"]="!(!y&x|z)|!y&x&z";
	ANS["10100111"]="!(!y&x|z)|x&z";
	ANS["10101000"]="!(x&y|z)";
	ANS["10101001"]="!(x&y|z)|x&y&z";
	ANS["10101010"]="!z";
	ANS["10101011"]="!z|x&y";
	ANS["10101100"]="!x&!z|!y&x";
	ANS["10101101"]="!(x&y|z)|x&z";
	ANS["10101110"]="!y&x|!z";
	ANS["10101111"]="!z|x";
	ANS["10110000"]="!(!y&z|x)";
	ANS["10110001"]="!x&!z|y&z";
	ANS["10110010"]="!(!y&x|z)|!x&y";
	ANS["10110011"]="!x&!z|y";
	ANS["10110100"]="!(!y&z|x)|!y&x&z";
	ANS["10110101"]="!(!y&z|x)|x&z";
	ANS["10110110"]="!(!y&x|z)|!x&y|!y&x&z";
	ANS["10110111"]="!x&!z|x&z|y";
	ANS["10111000"]="!x&y|!y&!z";
	ANS["10111001"]="!(x&y|z)|y&z";
	ANS["10111010"]="!x&y|!z";
	ANS["10111011"]="!z|y";
	ANS["10111100"]="!(!x&!y&z|x&y)";
	ANS["10111101"]="!x&!z|!y&x|y&z";
	ANS["10111110"]="!x&y|!y&x|!z";
	ANS["10111111"]="!z|x|y";
	ANS["11000000"]="!x&!y";
	ANS["11000001"]="!x&!y|x&y&z";
	ANS["11000010"]="!x&!y|!z&x&y";
	ANS["11000011"]="!x&!y|x&y";
	ANS["11000100"]="!(!z&x|y)";
	ANS["11000101"]="!x&!y|x&z";
	ANS["11000110"]="!(!z&x|y)|!z&x&y";
	ANS["11000111"]="!(!z&x|y)|x&y";
	ANS["11001000"]="!(x&z|y)";
	ANS["11001001"]="!(x&z|y)|x&y&z";
	ANS["11001010"]="!x&!y|!z&x";
	ANS["11001011"]="!(x&z|y)|x&y";
	ANS["11001100"]="!y";
	ANS["11001101"]="!y|x&z";
	ANS["11001110"]="!y|!z&x";
	ANS["11001111"]="!y|x";
	ANS["11010000"]="!(!z&y|x)";
	ANS["11010001"]="!x&!y|y&z";
	ANS["11010010"]="!(!z&y|x)|!z&x&y";
	ANS["11010011"]="!(!z&y|x)|x&y";
	ANS["11010100"]="!(!z&x|y)|!x&z";
	ANS["11010101"]="!x&!y|z";
	ANS["11010110"]="!(!z&x|y)|!x&z|!z&x&y";
	ANS["11010111"]="!x&!y|x&y|z";
	ANS["11011000"]="!x&z|!y&!z";
	ANS["11011001"]="!(x&z|y)|y&z";
	ANS["11011010"]="!(!x&!z&y|x&z)";
	ANS["11011011"]="!x&!y|!z&x|y&z";
	ANS["11011100"]="!x&z|!y";
	ANS["11011101"]="!y|z";
	ANS["11011110"]="!x&z|!y|!z&x";
	ANS["11011111"]="!y|x|z";
	ANS["11100000"]="!(x|y&z)";
	ANS["11100001"]="!(x|y&z)|x&y&z";
	ANS["11100010"]="!x&!y|!z&y";
	ANS["11100011"]="!(x|y&z)|x&y";
	ANS["11100100"]="!x&!z|!y&z";
	ANS["11100101"]="!(x|y&z)|x&z";
	ANS["11100110"]="!(!y&!z&x|y&z)";
	ANS["11100111"]="!x&!y|!z&y|x&z";
	ANS["11101000"]="!((x|y)&z|x&y)";
	ANS["11101001"]="!((x|y)&z|x&y)|x&y&z";
	ANS["11101010"]="!x&!y|!z";
	ANS["11101011"]="!x&!y|!z|x&y";
	ANS["11101100"]="!x&!z|!y";
	ANS["11101101"]="!x&!z|!y|x&z";
	ANS["11101110"]="!y|!z";
	ANS["11101111"]="!y|!z|x";
	ANS["11110000"]="!x";
	ANS["11110001"]="!x|y&z";
	ANS["11110010"]="!x|!z&y";
	ANS["11110011"]="!x|y";
	ANS["11110100"]="!x|!y&z";
	ANS["11110101"]="!x|z";
	ANS["11110110"]="!x|!y&z|!z&y";
	ANS["11110111"]="!x|y|z";
	ANS["11111000"]="!x|!y&!z";
	ANS["11111001"]="!x|!y&!z|y&z";
	ANS["11111010"]="!x|!z";
	ANS["11111011"]="!x|!z|y";
	ANS["11111100"]="!x|!y";
	ANS["11111101"]="!x|!y|z";
	ANS["11111110"]="!(x&y&z)";
	ANS["11111111"]="!x|x";
	int n;

	cin>>n;
	string temp;
	getline(cin,temp);

	for (;n;--n){
		string temp;
		getline(cin,temp);
		temp=ANS[temp];
		puts(temp.c_str());
	}



	cin.get(); cin.get();
	return 0;
}