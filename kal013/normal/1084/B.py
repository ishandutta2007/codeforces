n,s=map(int,raw_input().split())
l=map(int,raw_input().split())
l.sort()
su=sum(l)
if su<s:
    print -1
else:
    deff=su-s 
    mini=deff/n 
    print min(mini,l[0])