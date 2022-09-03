#include<cstdio>
#include<set>

char s[22];
std::set<int> V,H;
std::set<int>::iterator it,it1,it2;
std::multiset<int> VV,HH;

int main()
{
	int i,n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	V.insert(0);
	V.insert(n);
	VV.insert(n);
	H.insert(0);
	H.insert(m);
	HH.insert(m);
    while(l--)
	{
		scanf("%s%d",s,&i);
        if(s[0]=='V')
		{
            V.insert(i);
            it=it1=it2=V.find(i);
            it1++;
            it2--;
            VV.erase(VV.find(*it1-*it2));
            VV.insert(*it1-i);
            VV.insert(i-*it2);
		}
        else
		{
            H.insert(i);
            it=it1=it2=H.find(i);
            it1++;
            it2--;
            HH.erase(HH.find(*it1-*it2));
            HH.insert(*it1-i);
            HH.insert(i-*it2);
		}
		printf("%I64d\n",1LL*(*HH.rbegin())*(*VV.rbegin()));
	}
}