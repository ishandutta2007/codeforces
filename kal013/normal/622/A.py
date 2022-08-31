n=input()

x=int((2*n)**0.5)
while (x*(x+1)>2*n):
    x-=1 
while((x+1)*(x+2)<=2*n):
    x+=1 
res=n-(x*(x+1))/2
if (res==0):
    print x 
else:
    print res