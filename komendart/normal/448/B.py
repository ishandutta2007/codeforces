def main():
    s = input()
    t = input()
    
    i = 0
    for j in s:
        if j == t[i]:
            i += 1
            if i == len(t):
                print("automaton")
                return
    
    for i in range(26):
        c = chr(ord('a') + i)
        if s.count(c) < t.count(c):
            print("need tree")
            return
    
    if len(s) == len(t):
        print("array")
    else:
        print("both")


main()