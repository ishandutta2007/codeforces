def main():
    n = int(input())
    a = input().split()
    zero = 0
    st = "1"
    for s in a:
        if s == "0":
            print(0)
            return 0
        if s.count("1") != 1 or s.count("0") != len(s) - 1:
            st = s
        else:
            zero += len(s) - 1
    print(st + '0' * zero)
    
    
main()