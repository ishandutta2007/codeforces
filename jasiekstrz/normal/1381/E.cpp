#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long double EPS=0.000001;
struct P
{
	long double x,y;
};
P input[300010];
pair<int,int> f[100010];
long double wsp[100010][3];//0-1, 1-f, 2-f^2
long double answer[100010];
inline long double x_by_y(P p1,P p2,double y)
{
	return y*(p1.x-p2.x)/(p1.y-p2.y)+p1.x-p1.y*(p1.x-p2.x)/(p1.y-p2.y);
}
inline long double c(long double x1,long double x2,long double x3,long double x4,long double y1,long double y2,long double ff)
{
	return ff*2*(y1-y2)/(x1+x3-x2-x4)+y1-(y1-y2)*(x1+x3)/(x1+x3-x2-x4);
}
inline int bs(int n,long double x) //pierwszy wiekszy-rowny
{
	if(f[n].fi<x-EPS)
		return n+1;
	int b=1,e=n;
	while(b<e)
	{
		int mid=(b+e)/2;
		if(f[mid].fi>=x-EPS)
			e=mid;
		else
			b=mid+1;
	}
	return b;
}
inline int bs_c(int b,int e,long double x1,long double x2,long double x3,long double x4,long double y1,long double y2,long double x) //pierwszy z c wiekszym-rownym x
{
	while(b<e)
	{
		int mid=(b+e)/2;
		if(c(x1,x2,x3,x4,y1,y2,f[mid].fi)<x)
			b=mid+1;
		else
			e=mid;
	}
	if(c(x1,x2,x3,x4,y1,y2,f[b].fi)<x)
		return b+1;
	return b;
}
inline pair<int,int> bs_interval_c(int beg,int en,long double x1,long double x2,long double x3,long double x4,long double y1,long double y2)
{
	if(beg>en)
		return {beg,en};
	if(x3-x4<x2-x1)
	{
		swap(x1,x2);
		swap(x3,x4);
	}
	//c ronie
	return {bs_c(beg,en,x1,x2,x3,x4,y1,y2,y2),bs_c(beg,en,x1,x2,x3,x4,y1,y2,y1)-1};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<fixed<<setprecision(6);
	int n,q,max_y,g_max_y,i,j;
	long double x1,x3,y1,y2,x2,x4;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>input[i].x>>input[i].y;
		input[2*n+i]=input[n+i]=input[i];
	}
	for(i=1;i<=q;i++)
	{
		cin>>f[i].fi;
		f[i].se=i;
	}
	sort(f+1,f+q+1);
	max_y=input[n+1].y;
	g_max_y=n+1;
	for(i=n+2;i<=2*n;i++)
	{
		if(input[i].y>max_y)
		{
			max_y=input[i].y;
			g_max_y=i;
		}
	}
	if(x_by_y(input[g_max_y],input[g_max_y-1],max_y-1)>x_by_y(input[g_max_y],input[g_max_y+1],max_y-1))
	{
		for(i=1;i<n-i+1;i++)
			swap(input[i],input[n-i+1]);
		for(i=1;i<=n;i++)
			input[2*n+i]=input[n+i]=input[i];
		g_max_y=3*n-g_max_y+1;
	}
	x1=x3=input[g_max_y].x;
	y1=max_y;
	for(i=g_max_y-1,j=g_max_y+1;j-i-1<n;)
	{
		y2=max(input[i].y,input[j].y);
		x2=x_by_y(input[i+1],input[i],y2);
		x4=x_by_y(input[j-1],input[j],y2);
		//cerr<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<<y1<<" "<<y2<<"\n";
		////////////////////////////////////////////////////////////////
		int left_no=bs(q,min(x1,x2))-1,right_no=bs(q,max(x3,x4)),beg,en;
		//cerr<<left_no<<" "<<right_no<<"\n";
		wsp[1][0]+=(x3-x1+x4-x2)*(y1-y2);
		wsp[left_no+1][0]-=(x3-x1+x4-x2)*(y1-y2);
		wsp[right_no][0]+=(x3-x1+x4-x2)*(y1-y2);
		wsp[q+1][0]-=(x3-x1+x4-x2)*(y1-y2);
		if(x1+x3==x2+x4)
		{
			//nie ma przeciecia
			int b=left_no+1,e=right_no-1;
			if(f[right_no-1].fi-x1<x3-f[right_no-1].fi)
				b=right_no;
			while(b<e)
			{
				int mid=(b+e)/2;
				if(f[mid].fi-x1>x3-f[mid].fi)
					e=mid;
				else
					b=mid+1;
			}
			beg=b;
			en=b-1;
		}
		else
		{
			//jest przecicie
			pair<int,int> tmp=bs_interval_c(left_no+1,right_no-1,x1,x2,x3,x4,y1,y2);
			beg=tmp.fi;
			en=tmp.se;
		}
		//cerr<<beg<<" "<<en<<"\n";
		bool ch=false;
		int sgn=1;
		if(x3-x4>x2-x1)
		{
			ch=true;
			sgn=-1;
			swap(x1,x3);
			swap(x2,x4);
			x1=-x1;
			x2=-x2;
			x3=-x3;
			x4=-x4;
		}
		if(beg<=en)
		{
			long double a1=(x1-x2)/(y1-y2);
			long double b1=x1-y1*(x1-x2)/(y1-y2);
			long double a2=(x3-x4)/(y1-y2);
			long double b2=x3-y1*(x3-x4)/(y1-y2);
			long double ac=2*(y1-y2)/(x1+x3-x2-x4);
			long double bc=y1-(y1-y2)*(x1+x3)/(x1+x3-x2-x4);
			long double k1=2-a1*ac,l1=-x1-a1*bc-b1;
			long double k2=-ac,l2=y1-bc;
			long double k3=-2+a2*ac,l3=x4+a2*bc+b2;
			long double k4=ac,l4=bc-y2;
			//z przecieciem
			wsp[beg][2]+=k1*k2+k3*k4;
			wsp[en+1][2]-=k1*k2+k3*k4;
			wsp[beg][1]+=(k1*l2+k2*l1+k3*l4+k4*l3)*sgn;
			wsp[en+1][1]-=(k1*l2+k2*l1+k3*l4+k4*l3)*sgn;
			wsp[beg][0]+=l1*l2+l3*l4;
			wsp[en+1][0]-=l1*l2+l3*l4;
		}
		if(ch)
		{
			sgn=1;
			swap(x1,x3);
			swap(x2,x4);
			x1=-x1;
			x2=-x2;
			x3=-x3;
			x4=-x4;
		}
		//bez przeciecia , prawy sie liczy
		wsp[left_no+1][1]+=(-2*(y1-y2))*sgn;
		wsp[beg][1]-=(-2*(y1-y2))*sgn;
		wsp[left_no+1][0]+=(x3+x4)*(y1-y2);
		wsp[beg][0]-=(x3+x4)*(y1-y2);
		//bez przeciecia , lewy sie liczy
		wsp[en+1][1]+=(2*(y1-y2))*sgn;
		wsp[right_no][1]-=(2*(y1-y2))*sgn;
		wsp[en+1][0]+=-(x1+x2)*(y1-y2);
		wsp[right_no][0]-=-(x1+x2)*(y1-y2);
		//odjac zbedne
		int left_sub=bs(q,max(x1,x2))-1,right_sub=bs(q,min(x3,x4));
		//cerr<<left_sub<<" "<<right_sub<<"\n";
		//odjac lewy
		if(abs(x1-x2)>EPS)
		{
			long double ac=(y1-y2)/(x1-x2);
			long double bc=y1-x1*(y1-y2)/(x1-x2);
			if(x1>x2)
			{
				wsp[left_no+1][2]-=ac;
				wsp[left_sub+1][2]+=ac;
				wsp[left_no+1][1]-=(-y1+bc-ac*x1)*sgn;
				wsp[left_sub+1][1]+=(-y1+bc-ac*x1)*sgn;
				wsp[left_no+1][0]-=x1*y1-x1*bc;
				wsp[left_sub+1][0]+=x1*y1-x1*bc;
			}
			else
			{
				wsp[left_no+1][2]-=-ac;
				wsp[left_sub+1][2]+=-ac;
				wsp[left_no+1][1]-=(y2-bc+ac*x2)*sgn;
				wsp[left_sub+1][1]+=(y2-bc+ac*x2)*sgn;
				wsp[left_no+1][0]-=x2*bc-x2*y2;
				wsp[left_sub+1][0]+=x2*bc-x2*y2;
			}
		}
		//odjac prawy
		if(abs(x3-x4)>EPS)
		{
			long double ac=(y1-y2)/(x3-x4);
			long double bc=y1-x3*(y1-y2)/(x3-x4);
			if(x3<x4)
			{
				wsp[right_sub][2]-=-ac;
				wsp[right_no][2]+=-ac;
				wsp[right_sub][1]-=(y1-bc+ac*x3)*sgn;
				wsp[right_no][1]+=(y1-bc+ac*x3)*sgn;
				wsp[right_sub][0]-=x3*bc-x3*y1;
				wsp[right_no][0]+=x3*bc-x3*y1;
			}
			else
			{
				wsp[right_sub][2]-=ac;
				wsp[right_no][2]+=ac;
				wsp[right_sub][1]-=(bc-y2-ac*x4)*sgn;
				wsp[right_no][1]+=(bc-y2-ac*x4)*sgn;
				wsp[right_sub][0]-=x4*y2-x4*bc;
				wsp[right_no][0]+=x4*y2-x4*bc;
			}
		}
		//cerr<<wsp[1][0]<<"\n";
		////////////////////////////////////////////////////////////////
		if(input[i].y>input[j].y)
			i--;
		else if(input[j].y>input[i].y)
			j++;
		else
		{
			i--;
			j++;
		}
		y1=y2;
		x1=x2;
		x3=x4;
	}
	for(i=1;i<=q;i++)
	{
		wsp[i][0]+=wsp[i-1][0];
		wsp[i][1]+=wsp[i-1][1];
		wsp[i][2]+=wsp[i-1][2];
		answer[f[i].se]=wsp[i][2]*f[i].fi*f[i].fi+wsp[i][1]*f[i].fi+wsp[i][0];
	}
	for(i=1;i<=q;i++)
		cout<<answer[i]/2<<"\n";
	return 0;
}