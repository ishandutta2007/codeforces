hh,mm=map(int,raw_input().split(":"))
a=input()
mm+=a 

k=mm/60
mm%=60
hh+=k 
hh%=24
s=str(hh)
if hh<10:
    s="0"+s
s2=str(mm)
if mm<10:
    s2="0"+s2
print "%s:%s"%(s,s2)