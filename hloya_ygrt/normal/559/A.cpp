#include <bits\stdc++.h>

using namespace std;
#define dou double

const int eps=1e-8;
const double J=sqrt(3.0)/2.0;
//const double R=6371;
double sqr(dou d)
{
    return d*d;
}

struct pnt
{
    double x,y,z;

    pnt()
    {
        x=0;
        y=0;
        z=0;
    }
    pnt(dou _x,dou _y,dou _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }

    pnt(dou _x,dou _y)
    {
        x=_x;
        y=_y;
        z=0;
    }

    dou dist2(pnt A)
    {
        return sqr(((this->x)-A.x))+sqr((this->y)-A.y)+sqr((this->z)-A.z);
    }

    dou dist(pnt A)
    {
        return sqrt(this->dist2(A));
    }

    // 
    long double sq(pnt A,pnt B)
    {
        dou AB,BT,TA;
        long double p;
        AB=A.dist(B);
        BT=this->dist(B);
        TA=this->dist(A);

        p=AB+BT+TA;
        p/=2;
        return sqrt(p*(p-AB)*(p-BT)*(p-TA));
    }

};

long double sq(const vector<pnt> & polygon)
{
	long double s=0;
	for (int i=0;i<polygon.size();i++)
	{
		pnt p1 = i ? polygon[i-1] : polygon.back(), p2 = polygon[i];
        s+=(long double)(p1.x-p2.x)*(long double)(p1.y+p2.y);
	}
	return fabs(s)/2;
}

struct line
{
    dou k,b;
    bool bad;
    line (dou _k,dou _b)
    {
        k=_k;
        b=_b;
        bad=0;
    }
  line (dou _k,dou _b,bool z)
    {
        k=_k;
        b=_b;
        bad=1;
    }
    line (pnt A,pnt B)
    {
        if (A.x==B.x)
        {
            bad=1;
            k=A.x;
            b=A.x;
        }
        else
        {
            bad=0;
            k=(A.y-B.y)/(A.x-B.x);
            b=(A.y*(A.x-B.x)-A.x*(A.y-B.y))/(A.x-B.x);
        }
    }

    line perpendecular(pnt A)
    {
        if (bad)
        {
            dou k1=0;
            dou b1=A.x;
            return line(k1,b1);
        }
        else
        if (k!=0)
        {
            dou k1=(-1.0)/k;
            dou b1 = A.y-k1*A.x;
            return line(k1,b1);
        } else
        {
            dou k1=A.x;
            dou b1=A.x;
            return line(k1,b1,1);
        }
    }
};

pair<pnt,pnt> Move(pnt A,line l,dou len)
{
    if (l.bad==1) {
                pnt ans1 = pnt(A.x,A.y+len), ans2 = pnt (A.x,A.y-len);
                return make_pair(ans1,ans2);
    }
    else {
        dou x=A.x-sqrt(sqr(len)/(sqr(l.k)+1));
        pnt ans1 = pnt(x,l.k*x+l.b);
        x=A.x+sqrt(sqr(len)/(sqr(l.k)+1));
        pnt ans2 = pnt( x,l.k*x + l.b);

        return make_pair(ans1,ans2);
    }
}

int main()
{
    int d [ 6 ];
    for (int i = 0;i < 6; i++ )
        scanf ( "%d" , d + i );

    pnt a[ 6 ];
    a[0] = pnt( 0, 0);
    pnt core = pnt(0,0.5);
    a[1] = pnt( d[0], 0);
    for ( int i = 2 ; i < 6 ; i++) {
        line l=line( a[i-1] , a[i-2] );

        pair<pnt,pnt> C1 = Move(a[i-1] , l ,(double)d[i-1]/2.0 );
        pnt C;

        if ((C1.first).dist(a[i-1])<(C1.first).dist(a[i-2])&&d[i-2]*1.0<(C1.first).dist(a[i-2])+(C1.first).dist(a[i-1]))
        {
            C=C1.first;
        }
        else
        {
            C=C1.second;
        }

        line l1=l.perpendecular(C);
        pair<pnt,pnt> D1 = Move(C, l1 , sqrt(3)*d[i-1]/2);
        pnt D;
        if ((D1.first).dist(core)<(D1.second).dist(core))
            D=D1.first;
        else
            D=D1.second;
        a[i]=D;
    }

    /*vector<pnt> fig;
    for (int i=0;i<6;i++)
        fig.push_back(a[i]);
    long double sfigure=sq(fig);
  //  cout<<sfigure<<endl;
    long double summS=a[0].sq(a[1],a[5]);

    summS+=a[1].sq(a[2],a[3]);
    summS+=a[5].sq(a[4],a[3]);
    summS+=a[1].sq(a[3],a[5]);
    //cout<<summS<<endl;
    */
  //  for (int i=0;i<6;i++)
//cout<<a[i].x<<' '<<a[i].y<<endl;
 //   dou half=0.5;
 //   long double sinsq=(long double)d[0]*(long double)d[5];
 //   long double sinsq1=(long double)d[1]*(long double)d[2];
 //   long double sinsq2=(long double)d[3]*(long double)d[4];
 //   long double sinsq3=
   cout<< (d[0]+d[1]+d[2])*(d[0]+d[1]+d[2])-d[0]*d[0]-d[2]*d[2]-d[4]*d[4];
  //  long double striangle=sqrt(3.0)/4.0;

    //long double ans=sinsq/striangle;
   // cout<<round(ans);

//cout<<striangle<<endl<<sfigure;
    //pnt A=pnt(2.0,sqrt(3.0)),B=Move(A,line(sqrt(3),-sqrt(3)),0.5).second,C=Move(B,line(A,B).perpendecular(B),sqrt(3)/2.0).first;
   // printf("AB^2+BC^2=AC^2\n");
  //  cout<<C.x<<' '<<C.y;
  //  cout<<A.dist2(B)<<' '<<B.dist2(C)<<' '<<A.dist2(C)<<endl;
    return 0;
}