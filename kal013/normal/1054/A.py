x,y,z,t1,t2,t3=map(int,raw_input().split())
d=abs(y-x)
walk=d*t1 
ele=3*t3+d*t2+abs(z-x)*t2
if ele<=walk:
    print "YES"
else:
    print "NO"