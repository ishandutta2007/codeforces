
#A=input()
#B=input()


import sys
curr=0
print "? 0 0"
sys.stdout.flush()
def reply(a=0,b=0):
    x=input()
    return x
    """if A^a>B^b:
        return 1
    elif A^a==B^b:
        return 0
    else:
        return -1"""
curr=reply()

def solve0(a,b,ma=29):
    cnt=0
    for i in xrange(ma,-1,-1):
        x=(1<<i)
        print "? %d %d"%(a,b+x)
        sys.stdout.flush()
        curr=reply(a,b+x)
        if curr==1:
            cnt+=x
    return cnt

if curr==0:
    x=solve0(0,0,29)
    print "! %d %d"%(x,x)
    sys.stdout.flush()
else:
    cnt=0
    a=0
    b=0
    for i in xrange(29,-1,-1):
        x=(1<<i)
        if curr==1:
            print "? %d %d"%(a,b+x)
            sys.stdout.flush()
            curr=reply(a,b+x)
            if curr==1:
                a+=x
                print "? %d %d"%(a,b)
                sys.stdout.flush()
                curr=reply(a,b)
                if curr==-1:
                    b+=x
                curr=1
            elif curr==0:
                a+=x
                #print a,b
                uu=solve0(a,b,i-1)
                print "! %d %d"%(a+uu,b+uu)
                sys.stdout.flush()
                break
            else:
                print "? %d %d"%(a+x,b)
                sys.stdout.flush()
                curr=reply(a+x,b)
                if curr==1:
                    continue
                else:
                    a+=x
                    continue
        else:
            print "? %d %d"%(a+x,b)
            sys.stdout.flush()
            curr=reply(a+x,b)
            if curr==1:
                print "? %d %d"%(a,b+x)
                sys.stdout.flush()
                curr=reply(a,b+x)
                if curr==1:
                    b+=x
                continue
            elif curr==0:
                b+=x
                #print a,b
                uu=solve0(a,b,i-1)
                print "! %d %d"%(a+uu,b+uu)
                sys.stdout.flush()
                break
            else:
                b+=x
                print "? %d %d"%(a,b)
                sys.stdout.flush()
                curr=reply(a,b)
                if curr==1:
                    a+=x
                curr=-1