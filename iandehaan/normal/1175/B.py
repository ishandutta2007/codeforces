x = int(input())
x = 0
mx = 2**32
good = True
import sys
mults = []
mult = 1
yeet = False
lastMult = 0
for line in sys.stdin:
    inp = line.split()
    if inp[0] == "add":
        if lastMult == len(mults):
            x += mult
            if x >= mx:
                good = False
                print("OVERFLOW!!!")
                break
        else:
            # print(lastMult)
            # print(len(mults))
            good = False
            print("OVERFLOW!!!")
            break
    elif inp[0] == "for":
        mults.append(int(inp[1]))
        if lastMult == len(mults)-1:
            if mult*mults[-1] < mx:
                lastMult += 1
                mult *= mults[-1]

    else:
        if lastMult == len(mults):
            mult //= mults[-1]
            lastMult -= 1
        mults.pop()
if good:
    print(x)