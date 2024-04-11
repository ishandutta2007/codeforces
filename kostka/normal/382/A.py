def main():
    n = input().split('|')
    l = input()
    roz = len(n[0]) - len(n[1])
    if (roz%2) != (len(l)%2) or abs(roz) > len(l):
        print("Impossible")
    else:
        if roz>0:
            for i in range(abs(roz)):
                n[1] += l[i]
        else:
            for i in range(abs(roz)):
                n[0] += l[i]
        for i in range(abs(roz), len(l)):
            if i%2==0:
                n[0] += l[i]
            else:
                n[1] += l[i]
        print(n[0]+'|'+n[1])        

if __name__ == '__main__':
    main()