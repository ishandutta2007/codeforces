n,t = [int(i) for i in raw_input().split()]
s = "1" * (n-1)
for i in range(10):
    if (int(s + str(i)))%t == 0:
        if int(s + str(i)):
            print s+str(i)
            exit(0)
print -1