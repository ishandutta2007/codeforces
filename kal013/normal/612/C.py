s=raw_input()
op=["<","(","{","["]
cl=[">",")","}","]"]
d={op[i]:i for i in xrange(4)}
for i in xrange(4):
    d[cl[i]]=i
rem=0
flag=True
for i in s:
    if i in cl:
        rem-=1 
        if rem<0:
            flag=False
            break
    elif i in op:
        rem+=1 
stack=[]
if rem!=0 or not flag:
    print "Impossible"
else:
    ans=0
    
    for i in s:
        if i in cl:
            if d[i]!=d[stack[-1]]:
                ans+=1 
            stack.pop()
        if i in op:
            stack.append(i)
    print ans