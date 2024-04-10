#For fast I/O
#import sys
#input = lambda: sys.stdin.readline().strip()

#cost = max(0s left, 1s removed)
'''
Idea:
    Kinda like the supply and demand curve?
    0s left = demand curve (noninc)
    1s removed = supply curve (nondec)
    want min(supply, demand) -> find the intersection of the graphs
    This can be binary searched (O(logn))
    Do it for every prefix (O(nlogn))
    
    Since this is discrete, need to find both 
        max index with demand >= supply
        min index with supply >= demand

        OR

        only index with demand = supply



O(nlogn) sol:

O(n) preprocessing:
    Prefix
        prefix_0s[i] = number of 0s in prefix of length i
        prefix_1s[i] = number of 1s in prefix of length i
    Postfix
        postfix_0s[i] = number of 0s in postfix of length i
        postfix_1s[i] = number of 1s in postfix of length i


min_cost = initialize to number of 0s at the start

for each prefix of length i in range(l+1):
    binary search the max index with   "0s left >= 1s removed"
    min = 0
    max = i-1
    while max > min:
        mid = (min+max)//2
        0s left = init 0 - 0 prefix (mid) - 0 postfix (l-i)
        1s left = 1 prefix (mid) + 1 postfix (l-i)
        if 0s left >= 1s left:
            min = mid
        else:
            max = mid-1
    int = min or max
    check which of int or int+1 gives a lower cost (if int+1 is in range)
    min_cost = smaller of min_cost and current min_cost

print(min_cost)
'''



for Homu in range(int(input())):
    s = input()
    l = len(s)
    
    #PREPROCESSING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Number of 0s and 1s in the prefix of length i
    prefix_0s = [0]
    prefix_1s = [0]
    for i in range(l):
        if s[i] == '0':
            prefix_0s.append(prefix_0s[-1] + 1)
            prefix_1s.append(prefix_1s[-1])
        else:
            prefix_0s.append(prefix_0s[-1])
            prefix_1s.append(prefix_1s[-1] + 1)
    
    #Number of 0s and 1s in the postfix of length i
    postfix_0s = [0]
    postfix_1s = [0]
    for i in range(l):
        if s[l-1-i] == '0':
            postfix_0s.append(postfix_0s[-1] + 1)
            postfix_1s.append(postfix_1s[-1])
        else:
            postfix_0s.append(postfix_0s[-1])
            postfix_1s.append(postfix_1s[-1] + 1)
    
    #Number of 0s and 1s in s
    n0 = prefix_0s[l]
    n1 = prefix_1s[l]



    #BINARY SEARCH ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    #Initialize the minimum cost
    min_cost = n0

    #For each length postfix cut length
    for post_cut in range(l+1):
        #Binary search on removing a prefix from the rest
        Min = 0
        Max = l - post_cut
        while Max - Min > 1:
            Mid = (Min+Max)//2
            #Remaining 0s with pre/postfix len Mid/i
            rem_0s = n0 - prefix_0s[Mid] - postfix_0s[post_cut]
            #Removed 1s   with pre/postfix len Mid/i
            rem_1s = prefix_1s[Mid] + postfix_1s[post_cut]


            #Check which half to recurse on
            if rem_0s >= rem_1s:
                Min = Mid
            else:
                Max = Mid - 1
            
        if Max != Min:
            rem_0s = n0 - prefix_0s[Max] - postfix_0s[post_cut]
            #Removed 1s   with pre/postfix len Mid/i
            rem_1s = prefix_1s[Max] + postfix_1s[post_cut]
            if rem_0s >= rem_1s:
                Min = Max

        
        #Getting the two prefix cut lengths to check
        pre_cut_1 = Min
        if pre_cut_1 == l - post_cut:
            pre_cut_2 = Min
        else:
            pre_cut_2 = Min + 1

        #Cost from the 1st prefix cut length
        rem_0s_1 = n0 - prefix_0s[pre_cut_1] - postfix_0s[post_cut]
        rem_1s_1 = prefix_1s[pre_cut_1] + postfix_1s[post_cut]
        cost_1 = max(rem_0s_1, rem_1s_1)

        #Cost from the 2nd prefix cut length
        rem_0s_2 = n0 - prefix_0s[pre_cut_2] - postfix_0s[post_cut]
        rem_1s_2 = prefix_1s[pre_cut_2] + postfix_1s[post_cut]
        cost_2 = max(rem_0s_2, rem_1s_2)
        

        #Update the min cost
        min_cost = min(min_cost, cost_1, cost_2)

        #DEBUG

    print(min_cost)