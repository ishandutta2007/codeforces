tmp=[str(i) for i in xrange(10)]
def spl(s):
    a=[]
    b=[]
    res=""
    flag=True
    for i in xrange(len(s)):
        if s[i]=="," or s[i]==";":
            if len(res)==0 or (res[0]=="0" and len(res)>1):
                flag=False
            if flag and len(res)>0:
                a.append(res)
            else:
                b.append(res)
            res=""
            flag=True 
        else:
            if s[i] not in tmp:
                flag=False
            res+=s[i]
    if len(res)==0 or (res[0]=="0" and len(res)>1):
        flag=False
    if flag and len(res)>0:
        a.append(res)
    else:
        b.append(res)
    s1='"'
    if len(a)==0:
        s1="-"
    for i in xrange(len(a)):
        s1+=a[i]
        
        if i!=len(a)-1:
            s1+=','
        else:
            s1+='"'
    print s1
    s1='"'
    if len(b)==0:
        s1="-"
    for i in xrange(len(b)):
        s1+=b[i]
        
        if i!=len(b)-1:
            s1+=','
        else:
            s1+='"'
    print s1
s=raw_input()
spl(s)