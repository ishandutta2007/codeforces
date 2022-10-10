#include <bits/stdc++.h>
using namespace std;

static jmp_buf buf,buf2,buf3,buf4,buf5,buf6,buf7;

int n;
int data[15][15];
int risan = 0;

void f()
{

}

void one_d(int x, int y)
{
  y == n ? longjmp(buf2,1) : f();
  scanf("%d",&data[x][y]);
  one_d(x,y+1);
}

void two_d(int x)
{
  x == n ? longjmp(buf,1) : f();
  setjmp(buf2) ? f() : one_d(x, 0);
  two_d(x+1);
}

void i(int x,int y,int z)
{
  z == n ? longjmp(buf5,1) : f();
  data[y][z] = (data[y][z] < data[y][x] + data[x][z] ? data[y][z] : data[y][x] + data[x][z]);
  i(x,y,z+1);
}

void j(int x, int y)
{
  y == n ? longjmp(buf4,1) : f();
  setjmp(buf5) ? f() : i(x,y,0);
  j(x,y+1);
}

void k(int x)
{
  x == n ? longjmp(buf3,1) : f();
  setjmp(buf4) ? f() : j(x,0);
  k(x+1);
}

void jj(int x, int y)
{
  y == n ? longjmp(buf6,1) : f();
  risan = (risan > data[x][y] ? risan : data[x][y]);
  jj(x,y+1);
}

void kk(int x)
{
  x == n ? longjmp(buf7,1) : f();
  setjmp(buf6) ? f() : jj(x,0);
  kk(x+1);
}

int main()
{
  scanf("%d",&n);
  setjmp(buf) ? f() : two_d(0);
  setjmp(buf3) ? f() : k(0);
  setjmp(buf7) ? f() : kk(0);
  printf("%d\n",risan);
  return 0;
}