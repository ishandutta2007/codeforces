#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double db;
const ll MAXN=1e5+51;
struct Point3d{
	ll x,y,z;
};
typedef Point3d Vector3d;
Point3d poly[2][MAXN],nm[2];
Vector3d x;
vector<pair<db,pair<ll,ll>>>v;
ll ss,t;
db p;
ll cnt[2],s[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
} 
inline Vector3d operator +(Vector3d x,Vector3d y)
{
	return (Vector3d){x.x+y.x,x.y+y.y,x.z+y.z};
}
inline Vector3d operator -(Vector3d x,Vector3d y)
{
	return (Vector3d){x.x-y.x,x.y-y.y,x.z-y.z};
}
inline ll dot(Vector3d x,Vector3d y)
{
	return x.x*y.x+x.y*y.y+x.z*y.z;
}
inline Vector3d cross(Vector3d x,Vector3d y)
{
	return (Vector3d){x.y*y.z-x.z*y.y,x.z*y.x-y.z*x.x,x.x*y.y-y.x*x.y};
}
inline ll sgn(ll x)
{
	return x<0?-1:x?1:0;
}
int main()
{
	for(register int i=0;i<2;i++)
	{
		cnt[i]=read();
		for(register int j=0;j<cnt[i];j++)
		{
			poly[i][j].x=read(),poly[i][j].y=read(),poly[i][j].z=read();
		}
		poly[i][cnt[i]]=poly[i][0];
		nm[i]=cross(poly[i][1]-poly[i][0],poly[i][2]-poly[i][0]);
	}
	x=cross(nm[0],nm[1]);
	if(!dot(x,x))
	{
		return puts("NO"),0;
	}
	for(register int i=0;i<2;i++)
	{
		for(register int j=0;j<=cnt[i];j++)
		{
			s[j]=sgn(dot(poly[i][j]-poly[i^1][0],nm[i^1]));
		}
		for(register int j=0;j<cnt[i];j++)
		{
			if(s[j]^s[j+1])
			{
				p=dot(poly[i][j],x)+dot(poly[i][j+1]-poly[i][j],x)*(db)dot(nm[i^1],poly[i][j]-poly[i^1][0])/dot(nm[i^1],poly[i][j]-poly[i][j+1]);
				v.emplace_back(make_pair(p,make_pair(i,s[j]-s[j+1])));
			}
		}
	}
	sort(v.begin(),v.end());
	for(auto x:v)
	{
		x.second.first?ss+=t*x.second.second:t+=x.second.second;
	}
	puts(ss?"YES":"NO");
}